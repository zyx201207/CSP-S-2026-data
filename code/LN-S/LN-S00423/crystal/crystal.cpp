#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,maxn=-1;
    long long m,a[500005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        if(a[i]==a[i+1]) continue;
        int cnt=0;
        long long t=m;
        for(int j=i;j>=1;j--)
        {
            if(a[i]-a[j]<=t)
            {
                cnt++;
                t-=(a[i]-a[j]);
            }
            else break;
        }
        if(cnt>maxn) maxn=cnt;
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
