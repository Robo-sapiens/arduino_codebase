cppcheck `find -regex '\(.*[.]ino\)'` --enable=all --error-exitcode=1 --suppress=unusedFunction --error-exitcode=1
echo "cppcheck done"