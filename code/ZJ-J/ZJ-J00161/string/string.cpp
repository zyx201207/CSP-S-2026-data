#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
int n;
int ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int sum=0;
    while(n--)
    {
        int len;
        char s;
        cin>>len>>s;
        sum+=len;
        for(int i=1;i<=len;++i)a=a+s;
        for(int i=1;i<=len;++i)b=s+b;
    }
    for(int i=0;i<(sum+1)/2;++i)
    {
        if(a[i]!=b[i])ans++;
    }
    cout<<ans<<"\n";
    return 0;
}