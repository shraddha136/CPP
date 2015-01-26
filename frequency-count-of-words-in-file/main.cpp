    /**
     * main.cpp
     * Homework 5 - Counting frequency of each word in a text file
     * Author: Shraddha Atrawalkar
     */
    
    
    #include<iostream>
    #include<fstream>
    #include<map>
    #include <cstdlib>
    #include<string>
    #include<set>
    
    using namespace std;
    
    int main(int argc, char* argv[]) {
    
        //create a map container to store count of words
        map<string, int> freq_word;
        //string to store each word in the file
        string each_word;
        //string to store the executable name
        string arg = argv[0];
        //if the user does not provide the executable name and file name only, provide an error message
        if (argc != 2) {
          cerr << "Usage: \n\n" << "   " << arg.substr(2) << " filename\n" << endl;
          exit(2);
        } else {
            //open the file provided by the user
            ifstream fileinput(argv[1]);
            //if the file provided does not exist, provide an error message
            if (!fileinput.is_open()) {
                cerr << arg.substr(2) << ": " << argv[1] << ": No such file" << endl;
                exit(2);
            } else {
            
                //read the input file word by word.
                while (fileinput >> each_word) {
                        
                        for (string::size_type i = 0; i < each_word.size(); i++) {
                            //check for punctuation in the word read
                        if(each_word[0]=='\''){
                           size_t found = each_word.find_last_of('\'');
                           each_word.erase(found,1);
                           each_word.erase(0,1);
                    }
                            if(each_word[i]=='!'||each_word[i]=='.'||each_word[i]==','||
                                    each_word[i]=='?'||each_word[i]==';'||
                                    each_word[i]==':'||each_word[i]=='-'||
                                    each_word[i]=='|'){
                                    //if a punctuation is found in the word read, delete it
                                                each_word.erase(i, 1);
                                                //decrement the index to a previous position
                                                i -= 1;
                                    }
                               }
                        //store each word in the map and increment respective counts
                if(each_word!=""){
                             freq_word[each_word]++;
                        }
                }
                
                //read the map and display the word and its respective count
                for (map<string, int>::const_iterator iter = freq_word.begin();
                        iter != freq_word.end(); ++iter) {
                    cout << iter->first << ": " << iter->second << endl;
                }
                
                //close the read file
                fileinput.close();
            }
        }
    
        return 0;
    }
    