#include<bits/stdc++.h>
using namespace std;
int c,t,x[2200000];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(int z=1;z<=t;z++)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int time1=d/(x[2]-x[1]);
        int time=2*time1-1;
        int m=n-time;
        if(m<=0 || time1<=1) m=0;
        cout<<m<<'\n';
    }
    return 0;
}
