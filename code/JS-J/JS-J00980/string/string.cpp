#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a,cnt=0;
    char c;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int j=0;j<a;j++)
        {
            s+=c;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i] != s[s.size()-i-1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
