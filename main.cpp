#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>
#include<map>

using namespace std;
using std::find_if;
using std::istream;
using std::string;
using std::cin;


/**
vector<string> split(const string& s){
  typedef string::size_type str_size;
  str_size i =0;
  vector<string> ret;

  // while not end of the string
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
**/

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);

}

// split string into its constituent words
// using algorithm and iterator
vector<string> split(const string& s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();

    while(i!= s.end()){
        // find beginning of a word
        i = find_if(i, s.end(), not_space);

       // find the end of the word
       iter j = find_if(i, s.end(), space);

       // copy letter from i to j and append to the end of the string vector
        if(i!= s.end()){
        ret.push_back(string(i,j));
        i=j;
        }

   }
     return ret;
}

string::size_type width (const vector<string>& v){
    string::size_type maxLength = 0;
    // iterate through vector and return the length of the longest string
    for(vector<string>::size_type i=0; i!=v.size(); i++){
        maxLength = max(maxLength, v[i].size());

    }
    return maxLength;


}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    // get length of the longest string
    string::size_type maxLength = width(v);

    // top of the frame
    string border(maxLength+4, '*');
    ret.push_back(border);

    for(vector<string>::size_type i=0; i!=v.size(); i++){
       ret.push_back("* " + v[i] + string(maxLength-v[i].size(), ' ') + " *" );

    }

    // bottom of the frame
    ret.push_back(border);

    return ret;


}


istream& wordCounter(istream& in, map<string,int>& counters){
    string word;
    in >> word;
    ++counters[word];
    return in;
}

map<string, vector<int> > xref(istream& in, vector<string> find_word(const string&)=split){
    map<string, vector<int> > ret;
    string line;
    int line_number = 0;

    while(getline(in, line, ' ')){
        ++line_number;

        vector<string> word = find_word(line);

        for(vector<string>::const_iterator it = word.begin(); it!=word.end(); it++){

            ret[*it].push_back(line_number);
        }



    }

    return ret;

}


int main()
{
   /**
    string s;
    vector<string> result;
    vector<string> frame_v;


   while(getline(cin, s)){
    vector<string> result =split(s);
    frame_v = frame(result);


       for(vector<string>::size_type i=0; i!=frame_v.size(); i++){
        cout << frame_v[i] << endl;
       }
   }



   map<string,int> counters;
   while(wordCounter(cin, counters))

for(map<string,int>::const_iterator it= counters.begin(); it!=counters.end(); it++)
cout << (*it).first << " " << it->second;
**/

 map<string, vector<int> > result = xref(cin);

 for(map<string,vector<int> >::const_iterator it = result.begin(); it!=result.end(); it++){
    // write word or key of the map
    cout << it->first << "occur on line(s)";

   // write value of the stored by the key, which is a vector
   vector<int>::const_iterator line_it = it->second.begin();
   // first line number
    cout << *line_it;

    ++line_it;
   // write the rest of the line number
   while(line_it!=it->second.end()){
        cout << ","<< *line_it;
        ++line_it;
   }

  // write new line to separate word from next
  cout << endl;
 }


    return 0;
}
