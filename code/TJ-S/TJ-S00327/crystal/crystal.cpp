#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,s[500010];
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
    long long  ma=0;
    for(int i=1;i<=n;i++)
    {
        long long num=0,t=m;

        for(int j=1;j<=i;j++)
        {
            s[j]=abs(a[i]-a[j]);
        }
		sort(s+1,s+1+i);
        for(int j=1;j<=i;j++)
        {
            t-=s[j];
            if(t>=0)
            {
                num++;
            }
            else {
                break;
            }
        }
		ma=max(num,ma);
    }
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
