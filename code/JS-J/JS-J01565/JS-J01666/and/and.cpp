#include <bits/stdc++.h>
using namespace std;
bool a[200005][32],c[200005];
long long s[32];
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,b,t,ans=0;
	cin>>n>>m;
	m=10000;
	for(int i=1;i<=n;i++)
    {
        cin>>t;
        b=0;
        c[i]=1;
        while(t)
        {
            if(t&1)
            {
                s[b]++;
                a[i][b]=1;
            }
            t>>=1;
            b++;
        }
    }
    for(int i=29;i>=0;i--)
    {
        int d[200005];
        t=0,b=0;
        if(s[i]>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j][i] & c[j])
                    t++;
                 else if(c[j])
                 {
                     b++;
                     d[b]=j;
                 }
            }
            if(t>=m)
            {
                ans+=(1<<i);
                for(int j=1;j<=b;j++)
                    c[d[j]]=0;
            }
        }
    }
    cout<<ans;
    //for(int i=0;i<30;i++)cout<<s[i]<<' ';
	return 0;
}
