#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        char t;
        cin>>m>>t;
        for(int i=1;i<=m;i++)
        {
            s+=t;
        }
    }
    for(size_t i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
