#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int n;
ll m,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int cc,T;
    cin>>cc>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            bool flag=0,flag2=0;
            int la=i;
            for(int j=2;j<=n;j++)
            {
                if(a[j]-a[la]>m)
                {
                    if(la!=i)
                    {
                        if(la-1>i&&a[j-1]-a[la-1]<=m)
                            flag=1;
                        if(la-2>i&&a[j-1]-a[la-2]<=m)
                            break;
                        if(j-2!=la&&a[j-2]-a[la-1]<=m)
                            flag2=1;
                    }
                    int k=lower_bound(a+la+1,a+j+1,a[j]-m)-a;
                    //if(i==3&&j==9)
                        //cout<<"aaa "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                    if(k==j)
                        break;
                    else if(j-k==2)
                    {
                        if(!flag&&!flag2)
                        {
                            ans++;
                            //cout<<"aaa "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                        }
                        //else break;
                    }
                    else if(flag&&j-k==1)
                    {
                        ans++;
                        //cout<<"bbb "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                    }

                    la=j-1;
                }
                else
                {
                    int k=lower_bound(a+i,a+la+1,a[j]-m)-a;
                    //if(i==3&&j==9)
                     //   cout<<"aaa "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                    if(la-k+1==2&&!flag&&!flag2)
                    {
                        ans++;
                        //cout<<"ccc "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                    }
                    if(la==k&&flag)
                    {
                        ans++;
                        //cout<<"ddd "<<i<<" "<<j<<" "<<la<<" "<<k<<" "<<flag<<"\n";
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
