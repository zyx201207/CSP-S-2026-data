#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0,m=0;
const maxn=1e9+5;
char b[200005],c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int p=1;p<=a[i];p++)
        {
            m++;
           c[m]=b[i];
        }
    }
        for(int j=1;j<=m/2;j++)
        {
            if(c[j]!=c[m+1-j])ans++;
        }
        cout<<ans;
    return 0;
}
