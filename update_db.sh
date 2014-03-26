find . -name "*.h" -o -name "*.c" -o -name "*.S" > cscope.files
cscope -bkq -i cscope.files
ctags -R
