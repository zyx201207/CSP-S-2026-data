#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a;
ll len,res;
char c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        len=len+a*1LL;
        for(int j=1;j<=a;j++)
            s+=c;
    }
    for(ll i=0;i<len/2;i++)
        res+=(s[i]!=s[len-1-i]);
    cout<<res<<endl;
    return 0;
}
