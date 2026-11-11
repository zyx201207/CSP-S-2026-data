#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],cnt[500005];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[i]=1;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=2;i<=n;i++)
    {
        for(int k=1;k<=n;k++)b[i]=a[i];
        int num=m;
        for(int j=1;j<=i;j++)
        {

            if(num>=(b[i]-b[j])){
               num-=(b[i]-b[j]);
               cnt[i]++;
            }
        }
    }
    sort(cnt+1,cnt+n+1,cmp);
    cout<<cnt[2];
    return 0;
}
