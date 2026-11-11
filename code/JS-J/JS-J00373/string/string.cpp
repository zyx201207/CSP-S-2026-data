#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    else return gcd(y,x%y);
}
const int N=2e5+5;
int n;
ll add[N];
char ch[N];
string s=" ";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>add[i]>>ch[i];
    }
    int g=add[1];
    for(int i=2;i<=n;i++) g=gcd(g,add[i]);
    for(int i=1;i<=n;i++) add[i]/=g;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=add[i];j++) s+=ch[i];
    int len=s.size()-1;
    long long ans=0;
    for(int i=1;i<=len/2;i++)
    {
        if(s[i]!=s[len-i+1]) ans++;
    }
    cout<<ans*g<<endl;
}
