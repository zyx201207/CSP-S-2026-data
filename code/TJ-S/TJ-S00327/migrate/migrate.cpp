#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000080];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t;
    while(t--)
    {
        long long  n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
           if(a[2]-a[1]==a[3]-a[2])
           {
               if(d==1)cout<<0<<endl;
               else if(d==2)
               {
                   if(n<=3)cout<<0<<endl;
                   else cout<<1+n-4<<endl;;
               }
                else if(d>=3)
				{
					cout<<0<<endl;
				}
           }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
