#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <map>

using namespace std;

class Compiler {
	
private:
	std::vector<char> functions {'>', '<', '+', '-', '.', ',', '[', ']'};
	std::vector<int> memory = {0};
	int currentPtr = 0;
	int brktCount;
	std::map<int,std::string> levels;
	bool runLive;

public:
	
	Compiler(){
	
		this-> runLive = true;
		this-> brktCount=0;
	}
	
	
	void execCode(std::string code){
	
		std::cout << "EXEC REACHED " << std::endl;
		
		if(std::count(code.cbegin(), code.cend(), '[') != std::count(code.cbegin(), code.cend(), ']')){
			std::cout << "BRAINFK: Fatal Error: Unmatched Brackets []" << std::endl;
			exit(-1);
		}  
		
		
		for (char current : code){
		
			if (runLive){
				if (current == '>'){
					currentPtr++;
					if (memory.size() - 1 < currentPtr){
						memory.push_back(0);
					} 
				}	
				else if (current == '<' && currentPtr != 0){
					currentPtr--;
				}
				else if (current == '+'){
					memory[currentPtr]++;
					if (memory[currentPtr] > 255){
						memory[currentPtr] = 1;
					}
				}
				else if (current == '-'){
					memory[currentPtr]--;
					std::cout << "- reached" << std::endl;
					if (memory[currentPtr] < 0){
						memory[currentPtr] = 255;
					}
				}
				else if (current == '.'){
					std::cout << char(memory[currentPtr]);
				}
				else if (current == ','){
					char chr;
					std::cin >> chr;
					memory[currentPtr] = (int)chr;
				}
				else if (current == '['){
					brktCount++;
					this->runLive=false;
				}
			}
			else {
				if (current == ']'){
					//TODO: end loop, execute brakceted code if brkt level = 0 else read
					std::cout << "]" << std::endl;
					brktCount--;
					if (brktCount == 0){
						//execute code in brackets
						this->execCode(this->levels[this->brktCount]);
						this->runLive = true;
					}
					else {
						brktCount--;
					}
				} 
				else {
					this->levels[this->brktCount] += current;
					std::cout << this->levels[this->brktCount+1];
				}
			}
		}
	}
};

int main(int argc, char** argv){

	std::string str = std::string(argv[1]);
	std::string argument = "";
	for (auto chr : str){
		if (chr != ' '){
			argument += chr;
		}
	}

	std::string code;
	std::string linecode;
	
	if (argument == "-f"){
		std::ifstream file(argv[2]);
		while (getline (file, linecode)){
			code += linecode;
		}
	}
	else if (argument == "-s"){
		code = argv[2];
		std::cout << code << std::endl;
	}
	else if (argument == "-h" || argument == "--help"){
		std::cout << std::endl << "BRAINF COMPILER HELP:" << std::endl << std::endl;
		std::cout << "-h 		| --help			| displays help information" << std::endl;
		std::cout << "-v 		| --version			| displays compiler version" << std::endl;
		std::cout << "-f [path]	| --file 	[path]		| executes code at file path specified" << std::endl;
		std::cout << "-s [code]	| --string 	[code]		| executes code from inputted string" << std::endl << std::endl;
		
	}	
	else if (argument == "-v" || argument == "--version"){
		std::cout << "0.0.1" << std::endl;
	}
	else {
		std::cout << "BRAINF: FATAL ERROR: Incorrect format, try BRAINF --help" << std::endl;
	}
	
	
	auto _c = new Compiler();
	_c->execCode(code);
}


/*
is bracket

create new level
brkt ++

read until ]

brkt --

read until brkt


get next bracket
skip 




*/