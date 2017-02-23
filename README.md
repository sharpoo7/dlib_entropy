# dlib_entropy
Test of dlib entropy compressor/decompressor

# Compile
mkdir build
cd build
cmake ..
make

# txt to binary file
If the document is not in binary format, use txt2bin to convert, eg:
./txt2bin input.txt output.bin

# bin to txt
bin2txt is to convert binary file to txt format, eg:
./bin2txt data.bin output.txt

# test compression
./main -c --in data.bin --out compressed.bin
