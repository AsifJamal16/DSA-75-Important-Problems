//Count vowels and consonants in a string
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string lowercaseString(string str){
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        char lower=tolower(ch);
        str[i]=lower;
    }
    return str;
}
int charCount(string str,char ch){
    string lower=lowercaseString(str);
    int count=0;
    for(int i=0;i<lower.length();i++){
        if(lower[i]==ch){
            count++;
        }
    }
    return count;
}
int vowelCount(string str){
    string lower=lowercaseString(str);
    string vowel="aeiou";
    int vowelnumber=0;
    for(int i=0;i<vowel.length();i++){
        int input=charCount(lower,vowel[i]);
        vowelnumber=vowelnumber+input;
    }
    return vowelnumber;
}
int consonantsCount(string str){
    string lower=lowercaseString(str);
    string consonants="bcdfghjklmnpqrstvwxyz";
    int consonantnumber=0;
    for(int i=0;i<consonants.length();i++){
        int input=charCount(lower,consonants[i]);
        consonantnumber=consonantnumber+input;
    }
    return consonantnumber;
}

void conSonantsAndVowels(string str){
    int vo=vowelCount(str);
    int co=consonantsCount(str);
    cout<<vo<<" "<<co<<endl;
}
int main(){
    string str;
    getline(cin,str);
    conSonantsAndVowels(str);
    return 0;
}

