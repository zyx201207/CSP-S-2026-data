#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N],ans;
char c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i] >> c;
        for(int j = 0;j < a[i];j++) s+=c;
    }
    for(int i = 0;i < (s.size()-1)/2;i++)
    {
        if(s[i] != s[s.size()-1-i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
