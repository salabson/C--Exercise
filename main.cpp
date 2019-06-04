#include <iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

vector<string> split(string& s){
  typedef string::size_type str_size;
   str_size i =0;
   vector<string> ret;

   while(i!=s.size()){

    // find beginning of the word
    while(i!=s.size() && isspace(s[i]))
        i++;

    str_size j = i;

    // find end of the word
    while(j!=s.size() && !isspace(s[j]))
        j++;

    // word found, put it into vector
    if (i!=j){
        ret.push_back(s.substr(i, j-i));
         i=j;
    }


   }

   return ret;

}

int main()
{

    string s;
    vector<string> result;
   while(getline(cin, s)){
    vector<string> result =split(s);

       for(vector<string>::size_type i=0; i!=result.size(); i++){
        cout << result[i] << endl;
       }
   }



    return 0;
}
