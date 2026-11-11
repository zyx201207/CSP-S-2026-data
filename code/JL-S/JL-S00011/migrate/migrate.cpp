#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e6+5;
int c,t,n,y[MAXN];
long long d,x[MAXN],ans;
int fun(int s,int e)
{
    int sum=0,cnt=0;
    for(int i=s;i<e;i++)
    {
        sum++;
        for(int j=i+1;j<=e;j++)
            if(x[j]-x[i]<=d)
                y[sum]++;
        cnt=max(cnt,y[sum]);
    }
    return cnt;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<n;i++)
            cin>>x[i];
        for(int i=1;i<n-1;i++)
            for(int j=i+1;j<=n;j++)
                if(fun(i,j)==2)
                    ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
