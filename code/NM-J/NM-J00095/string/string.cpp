#include<bits/stdc++.h>
using namespace std;
char c;
long long a,n;
string s;
long long check(string s)
{
    long long ans=0;
    for(long long i=0,j=s.size()-1;i<j;i++,j--)if(s[i]!=s[j])ans++;
    return ans;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(long long j=1;j<=a;j++)s+=c;
    }
    cout<<check(s);
    return 0;
}
