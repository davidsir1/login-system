#include "file.hpp"

std::vector<std::string> passDelimetedString(std::string line){
	vector<std::string> result;
	std::stringstream s_stream{line};

	while(s_stream.good()){
		std::string subtr;
		std::getline(s_stream, subtr, ',');
		result.push_back(subtr);
	}

	return result;
}

void readFile(std::vector<std::string>& v){
	fstream myFile;
	std::string line;
	myFile.open("UsersRegistred.txt", fstream::in);

	if(!myFile.is_open()){
		std::cout << "Esse arquivo não existe!\n";
	}else{
		while(getline(myFile, line)){
			v = passDelimetedString(line);
		}

		myFile.close();
	}
}

