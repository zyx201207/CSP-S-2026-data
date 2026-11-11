#include<bits/stdc++.h>
using namespace std;
int n,h=1,t;
char s[200005];
long long a[200005],ans,k;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    t=n;
    while(h<t)
    {
        k=min(a[h],a[t]);
        a[h]-=k;
        a[t]-=k;
        if(s[h]!=s[t])ans+=k;
        if(a[h]==0)h++;
        if(a[t]==0)t--;
    }
    cout<<ans;
    return 0;
}
