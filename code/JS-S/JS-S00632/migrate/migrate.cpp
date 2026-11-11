#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],cnt,sum,s[2000010];
int main()
{

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
   while(t--)
    {
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++) s[i]=s[i+1]-s[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
               int x=a[j]-a[i];
               int k=i;
               while(x-s[k]>=0&&k<=j)
               {
                   x-=s[k];
                    k++;

               }
               if(x==0) cnt++;

            }
        }
        cout<<cnt<<endl;
    }
    return 0;

}


