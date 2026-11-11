#include<bits/stdc++.h>
using namespace std;
int c,t1,n;
long long d,x[2000005];
long long cnt,t;
long long minn=0x3f3f3f3f;
void a(int i,int j)
{
    if(i==j)
    {
        if(t<minn) {cnt=1;minn=t;}
        else if(t==minn) cnt+=1;
        return;
    }
    for(int k=i+1;x[k]-x[i]<=d&&k<=j;k++)
    {
        t+=1;
        a(k,j);
        t-=1;
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t1;
    for(int q=1;q<=t1;q++)
    {
        int sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=t=0;
                minn=0x3f3f3f3f;
                a(i,j);
                if(cnt==2) sum+=1;
            }
        }
        cout<<sum;
        if(t1!=q) cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
