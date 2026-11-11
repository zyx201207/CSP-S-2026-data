#include<iostream>
#include<algorithm>
using namespace std;
long long a[500090];
int n;
long long m,sum=0;
long long w(long long x)
{
    int idx=upper_bound(a+1,a+n+1,x)-a-1;
    long long d=m;
    long long cut=0;
    while(d>0)
    {
        if(idx==0)return cut;
        cut++;
        d-=(x-a[idx]);
        idx--;
    }
    if(d==0)return cut;
    cut--;
    return cut;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    //cin.tie(0);
    long long l=2e18,r=-2e18;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    sort(a+1,a+n+1);
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(w(mid)==upper_bound(a+1,a+n+1,mid)-a-1)l=mid+1;
        else r=mid-1;
        //cout<<w(mid)<<' '<<upper_bound(a+1,a+n+1,mid)-a-1<<"\n";
        cout<<l<<' '<<r<<"\n";
    }
    cout<<w(r);
    return 0;
}
