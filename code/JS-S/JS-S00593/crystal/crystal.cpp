#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,x;
long long a[514514],s[514514]={0};
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
    if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            x=0;
            for(int j=i;j>=1;j--)
            {
                x+=(a[i]-a[j]);
                if(x>m) break;
                s[i]++;
            }
            for(int i=1;i<=n;i++)
            {
                if(ans<=s[i]) ans=s[i];
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    else
    {
        x=a[2]-a[1];
        for(int i=1;i<=n;i++)
        {
            if((i-1)*x*i>2*m) cout<<i-1<<endl;
        }
    }
    return 0;
}
