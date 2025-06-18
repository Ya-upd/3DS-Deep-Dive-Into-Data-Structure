#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
         int n = s.size();
        stack<int> nums;
        stack<int> sgn;
        int result = 0;
        int ans = 0;
        int sign = 1;

        for (int i = 0; i < n; ++i) {
            char c = s[i];       
            if (isdigit(c)) {
                ans = 0;
                while (i < n && isdigit(s[i])) {
                    ans = ans * 10 + (s[i] - '0');
                    i++;
                }
                 i--;
                result += sign * ans;
            } 
            else if(c==' ') continue;
            else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                nums.push(result);
                sgn.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result = nums.top()+sgn.top()*result;
                nums.pop();
                sgn.pop();
            }
        }
        
        return result;
    }
};


int main()
{
    string s1;
    cout<<"ENTER A VALID STRING"<<endl;
    cin>>s1;
    Solution obj;
  int answer=  obj.calculate(s1);
  cout<<answer;

    return 0;
}