#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int countFloor(string s, int floor){
	char c;
        int count = 0;
	int n = 0;
        stack<char> solution;
        while(n < s.size() and count != floor){
                c = s.at(n);
                if (solution.empty()){
                        if (c == '(') count++;
                        else if (c == ')') count--;
                        solution.push(c);
                }else{
                        char prev = solution.top();
                        if (prev == c){
                                solution.push(c);
                                if (c == ')') count--;
                                else if (c == '(') count++;
                        }else{
                                solution.pop();
                                if (c == ')') count--;
                                else if (c == '(') count++;
                        }
                }
		n++;
        }
        return n;
}

int countDiff(string s){
	char c;
	int count = 0;
	stack<char> solution;	
	for(int n = 0; n < s.size();n++){
                c = s.at(n);
                if (solution.empty()){
                        if (c == '(') count++;
                        else if (c == ')') count--;
                        solution.push(c);
                }else{
                        char prev = solution.top();
                        if (prev == c){
                                solution.push(c);
                                if (c == ')') count--;
                                else if (c == '(') count++;
                        }else{
                                solution.pop();
                                if (c == ')') count--;
                                else if (c == '(') count++;
                        }
                }
        }
	return count;
}

int main () {
	ifstream parenthe;
	string data;
	parenthe.open("data.txt");
	getline(parenthe,data);
	parenthe.close();
	int count = countDiff(data);
	cout<<"The floor the directions lead to is floor "<<count<<endl;
	int position = countFloor(data, -1);
	cout<<"The position of the first character that leads to the basement (-1) is position "<<position<<endl;
	return 0;
}
