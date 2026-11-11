#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool f[N];
string s[N];
string szp(int x)
{
    if(!x) return "0";
    string t="";
    while(x)
    {
        int g=x%2;
        t=char(g+48)+t;
        x/=2;
    }
    return t;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=szp(a[i]);
        while(s[i].size()<30) s[i]='0'+s[i];
    }
    for(int i=30;i>=1;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j]) continue;
            if(s[j][30-i]=='1') cnt++;
        }
        if(cnt>=m)
        {
            ans+=(1<<(i-1));
            for(int j=1;j<=n;j++) if(s[j][30-i]=='0') f[j]=1;
        }
    }
    cout<<ans;
	return 0;
}
