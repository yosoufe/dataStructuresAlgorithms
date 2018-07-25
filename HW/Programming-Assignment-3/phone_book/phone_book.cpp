#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include "hashing.h"

using std::string;
using std::vector;
using std::cin;

struct Query {
  string type, name;
  int number;
};

hashMap<string, int> name2num;
hashMap<int, string> num2name;

vector<Query> read_queries_from_file(std::string filePath) {
  std::ifstream file;
  std::string word;
  file.open(filePath);
  vector<Query> queries;

  unsigned int n;
  if (file >> n)
    queries.resize(n);
  else return queries;

  for (unsigned int i = 0; i < n; ++i) {
    file >> queries[i].type;
    if (queries[i].type == "add")
      file >> queries[i].number >> queries[i].name;
    else
      file >> queries[i].number;
  }
  return queries;
}

vector<Query> read_queries() {
  unsigned int n;
  cin >> n;
  vector<Query> queries(n);
  for (unsigned int i = 0; i < n; ++i) {
    cin >> queries[i].type;
    if (queries[i].type == "add")
      cin >> queries[i].number >> queries[i].name;
    else
      cin >> queries[i].number;
  }
  return queries;
}

void write_responses(const vector<string>& result) {
  for (size_t i = 0; i < result.size(); ++i)
    std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
  vector<string> result;
  // Keep list of all existing (i.e. not deleted yet) contacts.
  vector<Query> contacts;
  for (size_t i = 0; i < queries.size(); ++i)
    if (queries[i].type == "add") {
      bool was_founded = false;
      // if we already have contact with such number,
      // we should rewrite contact's name
      for (size_t j = 0; j < contacts.size(); ++j)
        if (contacts[j].number == queries[i].number) {
          contacts[j].name = queries[i].name;
          was_founded = true;
          break;
        }
      // otherwise, just add it
      if (!was_founded)
        contacts.push_back(queries[i]);
    } else if (queries[i].type == "del") {
      for (size_t j = 0; j < contacts.size(); ++j)
        if (contacts[j].number == queries[i].number) {
          contacts.erase(contacts.begin() + int(j));
          break;
        }
    } else {
      string response = "not found";
      for (size_t j = 0; j < contacts.size(); ++j)
        if (contacts[j].number == queries[i].number) {
          response = contacts[j].name;
          break;
        }
      result.push_back(response);
    }
  return result;
}

vector<string> process_queries_withHashing(const vector<Query>& queries) {
  vector<string> result;
  // Keep list of all existing (i.e. not deleted yet) contacts.
  vector<Query> contacts;
  for (size_t i = 0; i < queries.size(); ++i)
    if (queries[i].type == "add") {
      bool was_founded = false;
      // if we already have contact with such number,
      // we should rewrite contact's name
      auto pair = num2name.find(queries[i].number);
      if( pair != num2name.end())
      {
        was_founded = true;
        string oldName = pair->value;
        pair->value = queries[i].name;
        name2num.remove(oldName);
        name2num.add(queries[i].name, queries[i].number);
      }
      // otherwise, just add it
      if (!was_founded)
      {
        name2num.add(queries[i].name,queries[i].number);
        num2name.add(queries[i].number,queries[i].name);
      }
    } else if (queries[i].type == "del") { // del by number
      auto node = num2name.find(queries[i].number);
      if(node != num2name.end())
      {
        num2name.remove( queries[i].number );
        name2num.remove( queries[i].name );
      }
    } else { // find name by number = find
      string response = "not found";
      auto pair = num2name.find(queries[i].number);
      if( pair != num2name.end())
      {
        response = pair->value;
      }
      result.push_back(response);
    }
  return result;
}


void test1(){
  using namespace std;
//  hashMap<int,int> mp;
//  mp.add(110,0);
//  mp.add(15,1);
//  volatile auto t = mp.end();
//  cout<< mp.find(20)->value << " " << (mp.find(20) == mp.end()) << endl;

  hashMap<string,int> mp_str;
  mp_str.add("yousof",0);
  mp_str.add("farnaz",1);
  //volatile auto t = mp_str.end();
  cout<< mp_str.find("yousof")->value << " " << (mp_str.find("yousof") == mp_str.end()) << endl;
  cout<< mp_str.find("farnaz")->value << " " << (mp_str.find("farnaz") == mp_str.end()) << endl;
  cout<< mp_str.find("test")->value << " " << (mp_str.find("test") == mp_str.end()) << endl;


}


/**
 * @brief main
 * @return
 *
 * For this example I am using two mappings
 * phone number -> index of the queries vector
 * name -> index of the queries vector
 */
int main() { 
  //write_responses(process_queries(read_queries()));
  write_responses(process_queries_withHashing(read_queries_from_file("../HW/Programming-Assignment-3/phone_book/queries")));


  //test1();
  return 0;
}
