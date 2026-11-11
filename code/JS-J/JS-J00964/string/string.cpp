#include <bits/stdc++.h>

using namespace std;
long long a[200005];
char b[200005];
int n;
long long maxn=0;
long long jl=0;
long long cnt=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        maxn+=a[i];
    }
    int i=1;
    int j=n;
    if(maxn%2!=0)
    {
        maxn+=1;
    }
    while(jl<=maxn/2)
    {
        jl+=a[i];
        long long mor=0;
        if(jl>maxn/2)
        {
            mor=jl-maxn/2;
        }
        long long t=a[i]-mor;
        while(t>0)
        {
            if(b[i]!=b[j])
            {
                if(t>=a[j])
                {
                    cnt+=a[j];
                    t-=a[j];
                    j--;
                }
                else
                {
                    cnt+=t;
                    a[j]-=t;
                    t=0;
                }
            }
            else
            {
                if(t>=a[j])
                {
                    t-=a[j];
                    j--;
                }
                else
                {
                    a[j]-=t;
                    t=0;
                }
            }
        }
        i++;
    }
    cout << cnt << endl;
    return 0;
}
