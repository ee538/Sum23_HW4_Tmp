# Note to students: please ignore all files in this folder.
bazel test --cxxopt='--std=c++17' $(bazel query //sol/... | grep grader)
bazel build --cxxopt='--std=c++17' $(bazel query //sol/... | grep non_coding_q)
rm -rf files
cp -r sol files
cd files/
find . -name grader_test.cc -exec rm -rf {} \;
find . -name SOLUTION.* -exec rm -rf {} \;
find . -maxdepth 1 -exec cp ../template/q.cc {} \;
find . -maxdepth 1 -exec cp ../template/student_test.cc {} \;
rm -rf {q.h,q.cc,test_all.csh,student_test.cc}
# Only for non-coding questions:
export non_coding_directories=""

# Loop through each directory name
for dir in $non_coding_directories; do
  # Use the directory name in the command to remove the file
  echo "$dir"/q.cc
  rm -rf "$dir"/q.cc
done

cd ../

git add files
git commit -a -m "Created files folder"
git push
