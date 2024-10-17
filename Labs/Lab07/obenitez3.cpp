

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int hashSize;
vector<list<int>> hashTable;


void insert(int key) {
    int index = key % hashSize;
     hashTable[index].push_front(key);
}

bool remove(int key) {
    int index = key % hashSize;
    list<int>& bucket = hashTable[index];
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (*it == key) {
      bucket.erase(it);
      return true;
    }
  }
  return false;
}

void search(int key) {
  int index = key % hashSize;
  list<int>& bucket = hashTable[index];
  int i = 0;
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (*it == key) {
      cout << key << ":FOUND_AT" << index << "," << i << ";" << endl;
      return;
    }
    i++;
  }
  cout << key << ":NOT_FOUND;" << endl;
}

void output() {
  for (int i = 0; i < hashSize; i++) {
    cout << i << ":";
    for (int key : hashTable[i]) {
      cout << key << "->";
    }
    cout << ";" << endl;
  }
}

int main(int argc, char const *argv[]) {

  bool repeat = true;

  string input = "";
  cin >> hashSize;
  hashTable.resize(hashSize);

  //

  do{
      int number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' && input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
        insert(number);
      }else if(input[0] == 'd'){
        if (remove(number)) {
          cout << number << ":DELETED;" << endl;
        } else {
          cout << number << ":DELETE_FAILED;" << endl;
        }
      }else if(input[0] == 's'){
        search(number);
      }else if(input[0] == 'o'){
        output();
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}


