#include <bits/stdc++.h>
using namespace std;
int n;
long long a;
char c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for(int j = 1;j <= a;j++)
        {
            s+=c;
        }
    }
    long long left = 1,right = s.size()-1;
    long long cnt = 0;
    while(true)
    {
        if(s[left]!=s[right])
        {
            cnt++;
        }
        left++;
        right--;
        if((right-left)<=1)
        {
            if(cnt!=0)
            {
                cnt++;
            }
            cout << cnt;
            return 0;
        }
    }
    return 0;
}
