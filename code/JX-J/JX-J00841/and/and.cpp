#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,num,tmp,tmp2,cnt,k,a[200005],t[35][4005];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(flase);
    cin.tie(nullptr);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        tmp=a[i];
        while(tmp>0)
        {
            tmp/=2;
            cnt++;
            k*=2;
        }
        for(long long j=0;j<cnt;j++)
        {
            if(a[i]>=k)
            {
                a[i]-=k;
                t[cnt-j-1][i]++;
                if(a[i]==0) break;
            }
            k/=2;
        }
        k=1;
    }
    for(long long i=0;i<n;i++)
    {
        tmp2=n-i;
        for(long long j=i+1;j<=tmp2;j++)
        {
            k=1;
            for(long long c=0;c<=30;c++)
            {
                if(t[c][i]==1&&t[c][j]==1)
                {
                    num+=k;
                    cout<<i<<endl;
                }
                k*=2;
            }
            if(num>maxx) maxx=num;
        }
    }
    cout<<maxx;
    return 0;
}
