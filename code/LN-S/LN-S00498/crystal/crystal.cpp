#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int n;
long long m;
int l=1,r=1;
long long cnt=0;
int siz=1;
int mx=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(l<=r&&r<n)
    {
        r++;
        siz++;
        cnt+=(a[r]-a[r-1])*(siz-1);
       // cout<<cnt;
        while(cnt>m&&l<n)
        {
            cnt-=(a[r]-a[l]);
            l++;
            siz--;
        }
       // cout<<siz<<endl;
        mx=max(mx,siz);
    }
    cout<<mx;
    return 0;
}
