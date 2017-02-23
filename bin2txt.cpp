#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    if(argc<3){
        cerr << "Usage: " << argv[0] << " infile outfile" << endl;
        exit(-1);
    }
    std::string filename = argv[1];

    std::ifstream in(filename, std::ios::binary);

    // copies all data into buffer
    std::vector<uint8_t> input( (std::istreambuf_iterator<char>(in)),
            			(std::istreambuf_iterator<char>()));
    in.close();
    cout << "read file size: " << input.size();

    auto maxv = std::max_element(input.begin(), input.end());
    auto minv = std::min_element(input.begin(), input.end());
    cout << "max min values: " << (int)(*maxv) << " " << (int)(*minv) << endl;

    ofstream out(argv[2]);
    for(auto it : input){
        out << (int)it << "\n";
    }
    out.close();

    return 0;
}
