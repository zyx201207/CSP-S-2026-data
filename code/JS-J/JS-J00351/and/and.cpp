#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        long long result=0;
        for(int mask=0;mask<(1<<n);mask++)
        {
            int cnt=0;
            int flag=0;
            long long ret=0;
            for(int i=1;i<=n;i++)
            {
                if(mask&(1<<(i-1)))
                {
                    cnt++;
                    if(flag==0)
                    {
                        flag=1;
                        ret=a[i];
                    }
                    else
                    {
                        ret=ret&a[i];
                    }
                }
            }
            if(cnt==m)
            {
                result=max(result,ret);
            }
        }
        cout<<result;
    }
    else if(m==1)
    {
        long long cntc=0;
        for(int i=1;i<=n;i++)
        {
            cntc=max(cntc,a[i]);
        }
        cout<<cntc;
    }
    else if(m==n)
    {
        long long cntcc=a[1];
        for(int i=2;i<=n;i++)
        {
            cntcc&=a[i];
        }
        cout<<cntcc;
    }
    else if(m==2)
    {
        long long retr=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                long long sum=a[i]&a[j];
                retr=max(retr,sum);
            }
        }
        cout<<retr;
    }
    return 0;
}
