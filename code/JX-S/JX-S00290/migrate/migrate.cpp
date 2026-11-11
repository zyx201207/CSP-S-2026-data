#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],cnt=0;
long long ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+3;j<=n;j++)
            {cnt=0;
                if(abs(a[i]-a[j])<=d) continue;
                for(int q=i+1;q<j;q++)
                {

                if(a[q]-a[i]<=d)//i->q true
                {
                    if(a[j]-a[q]<=d)//q->j true
                    {
                        if(a[q+1]-a[i]<=d&&a[q+2]-a[i]>d)//only two ways can go to the j(a->q+1 true && q+1->j true && i->q+2 false (you can't go to the q+2 then go to the j))
                        {
                            ans++;//ways +1
                        }
                        break;
                    }
                }
                else break;
                }
            }
        }
        cout<<ans<<"\n";
        ans=0;//clear
    }

    return 0;
}
