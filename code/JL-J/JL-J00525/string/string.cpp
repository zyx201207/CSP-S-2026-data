#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt=0;
char g;
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>a>>g;
        for(long long i=0;i<a;i++)
        {
            s+=g;
        }
    }
    for(long long i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            s[s.size()-1-i]=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
