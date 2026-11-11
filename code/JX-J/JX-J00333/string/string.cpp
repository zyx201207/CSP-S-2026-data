#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,ans=0;
char c[200005],b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(long long j=1;j<=a[i];j++)
        {
            b[ans]=c[i];
            ans++;
        }
    }
    for(int i=1;i<=ans/2;i++)
    {
        if(b[i]!=b[ans-i])
        {
            sum++;
            //cout<<b[i]<<b[ans-i];
        }
    }
    cout<<sum;
    return 0;
}
