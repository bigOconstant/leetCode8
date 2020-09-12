#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;
using std::string;

string  removeLeadingWhiteSpace(string str,int &sign,bool signset){

  if(str.length() <1){
    return "";
  }
  if(str[0] == ' ') {
    if(signset){
      return "fail";
    }
    return removeLeadingWhiteSpace(str.substr(1,str.length()),sign,false);
  }
  if(str[0] == '-') {
    if(!signset){
      sign = -1;
      return removeLeadingWhiteSpace(str.substr(1,str.length()),sign,true);
    }else{
      return str;
    }
  }
  if(str[0] == '+') {
    if(!signset){
      sign = 1;
      return removeLeadingWhiteSpace(str.substr(1,str.length()),sign,true);
    }else{
      return str;
    }
  }

  return str;
  
}

int convert(string str, int value, int sign, int dec){

  if(str.length() < 1 || !isdigit(str[0])) {
    return value * sign;
  }

  if(value > INT32_MAX/10 || (value == INT32_MAX/10) && (str[0] - '0') > INT32_MAX % 10){
    
    return (sign == 1) ? INT32_MAX : INT32_MIN;
  }
      
 
  int next = (value * dec) + (str[0] - '0');
  return convert(str.substr(1,str.length()),next,sign,10);
  
}

int myAtoi(string str) {

  int sign = 1;
  str = removeLeadingWhiteSpace(str,sign,false);
  
  return convert(str,0,sign,1);
  
}




int main(int argc, char **argv) {
    std::cout << "Leet Code Problem 8, string to Integer" << std::endl;
    //   cout<<"answer:"<<myAtoi("-+42")<<endl;
     cout<<"answer:"<<myAtoi("-   234")<<endl;
     cout<<"answer:"<<myAtoi("42")<<endl;
     cout<<"answer:"<<myAtoi("    42")<<endl;
     cout<<"answer:"<<myAtoi("4193 with words")<<endl;
     cout<<"answer:"<<myAtoi("words and 987")<<endl;
   
     cout<<"answer:"<<myAtoi("-91283472332")<<endl;
   
    return 0;
}
