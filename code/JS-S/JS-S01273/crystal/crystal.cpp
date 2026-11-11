#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e15;
const long long MINN=-1e15;
int n;
long long m;
long long a[500005];
bool flag=1;
long long mngap=MAXN;
long long mxgap=MINN;
long long sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) flag=0;
        mngap=min(mngap,a[i]-a[i-1]);
        mxgap=max(mxgap,a[i]-a[i-1]);
    }
    if(flag==1||mngap==mxgap)
    {
        long long res=0;
        long long cnt=1;
        for(int i=n-1;i>=1;i--)
        {
            res+=(n-i)*mngap;
            if(res>m) break;
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    sort(a+1,a+n+1);
    sum[0]=0;
    sum[1]=a[1];
    long long mxcnt=0;
    for(int i=2;i<=n;i++)
    {
        sum[i]=a[i]-a[i-1]+sum[i-1];
        long long cnt=1;
        long long nowans=0;
        for(int j=i-1;j>=1;j--)
        {
            nowans+=sum[i]-sum[j];
            if(nowans>m) break;
            cnt++;
        }
        mxcnt=max(mxcnt,cnt);
    }
    cout<<mxcnt;
    return 0;
}
