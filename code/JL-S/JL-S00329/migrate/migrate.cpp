#include<bits/stdc++.h>
using namespace std;
int x[20000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    int t1;
    int ans;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        for(int a=1;a<n;a++)
        {
            for(int b=a+1;b<=n;b++)
            {
                t1=0;
                for(int j=a+2;j<=b;j++)
                {
                    if(x[j]-x[j-2]<=d)
                    {
                        t1+=1;
                    }
                }
                if(t1%2==0&&t1!=0)
                {
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
