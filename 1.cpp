//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。

// 输入描述:
// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.

// 输出描述:
// 对于每组数据，输出一个整数，代表最少需要删除的字符个数。

// 输入例子1:
// abcda
// google

// 输出例子1:
// 2
// 2

#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  
  
string converseString(string str){  
    int size = str.size();  
    if (size < 2) return str;  
    int front = 0, rear = size - 1;  
    while(front < rear){  
        char temp = str[front];  
        str[front] = str[rear];  
        str[rear] = temp;  
        front++;  
        rear--;  
    }  
    return str;  
}  
  
  
int max(int a, int b){  
    return a>b ? a : b;  
}  
  
  
int GetLCS(string s1, string s2){  
    int size = s1.size();  
    int curMax = 0;  
    vector<vector<int> > DP(size + 1, vector<int>(size + 1, 0));  
    for (int i = 0; i <= size; i++)  
    {  
        DP[i][0] = 0;  
        DP[0][i] = 0;  
    }  
    for (int i = 1; i <= size; i++)  
        for (int j = 1; j <= size; j++){  
            if (s1[i - 1] == s2[j - 1])  
                DP[i][j] = DP[i - 1][j - 1] + 1;  
            else  
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);  
            if (DP[i][j] > curMax)  
                curMax = DP[i][j];  
        }  
    return curMax;  
}  
  
int core(string str){  
    string converseStr = converseString(str);  
    return str.size() - GetLCS(str, converseStr);  
}  
  
int main(int argc, char* argv[])  
{  
	string s;
	while(cin >> s){
		cout << core(s) << endl;  	
	}
    return 0;  
}  