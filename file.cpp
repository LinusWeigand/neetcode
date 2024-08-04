#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

float average(const vector<int>& numbers) {
  float sum = 0;
  for (int i : numbers) {
    sum += i;
  }
  return sum / numbers.size();
}

bool isAnagram(string s, string t) {
    unordered_map<char, int> count{};
    for(char i: s) {
        count[i] += 1;
    }
    for(char i: t) {
        count[i] -= 1;
    }
    for(const pair<char, int> n: count) {
        if (n.second != 0) {
            return false;
        }
    }
    return true;
}

// O ((n-1) * n / 2)    
bool hasDuplicate(vector<int>& nums) {
    vector<int> seen{};
    for (int i : nums) {
        for(int j: seen) {
            if (i == j) {
                return true;
            }
        }
        seen.push_back(i);
    }
    return false;
}

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j < nums.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {0, 1};
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> temp = strs;
    vector<vector<string>> result;
    while(temp.size() > 0) {
        string s = temp.back();
        temp.pop_back();
        vector<string> group;
        group.push_back(s);

        for(auto it = temp.begin(); it != temp.end(); ) {
            if(isAnagram(s, *it)) {
                group.push_back(*it);
                it = temp.erase(it);
            } else {
                ++it;
            }
        } 
        result.push_back(group);
    }
    return result;
}

void printVectorOfVector(const vector<vector<string>>& vec) {
    for_each(vec.begin(), vec.end(), [](const vector<string>& inner) {
        for_each(inner.begin(), inner.end(), [](const string& item) {
            cout << item << " ";
        });
        cout << endl;
    });
}

void printVector(const vector<int>& vec) {
    for_each(vec.begin(), vec.end(), [](const int& item) {
        cout << item << " ";
    });
    cout << endl;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(int i: nums) {
        count[i] += 1;
    }
    vector<pair<int, int>> vec(count.begin(), count.end());
    sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second < b.second; });

    vector<int> result;
    for(int i = 0; i < k; ++i) {
        result.push_back(vec.back().first);
        vec.pop_back();
    }
    return result;
}

int main() {
    vector<int> nums{1,2, 3, 4, 3, 2, 3, 2, 4};
    vector<int> result = topKFrequent(nums, 3);
    
    printVector(result);
    return 0;
}