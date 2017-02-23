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
    std::string filename_out = argv[2];

    ifstream in(filename);

    std::vector<uint8_t> input;
    if(in.is_open()){
        while (in.good()) {
            int c;
            in >> c;
            if(in.eof())break;
            input.push_back( static_cast<uint8_t>(c) );
        }
    }
    in.close();
    cout << "read file size: " << input.size();

    auto maxv = std::max_element(input.begin(), input.end());
    auto minv = std::min_element(input.begin(), input.end());
    cout << "max min values: " << (int)(*maxv) << " " << (int)(*minv) << endl;

    ofstream out(filename_out, ios::binary);
    for(auto it : input){
        out << it;
    }
    out.close();

    return 0;
}
