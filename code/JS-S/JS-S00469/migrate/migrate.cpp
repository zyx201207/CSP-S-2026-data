#include<bits/stdc++.h>
#define N 2000010
#define  int long long
using namespace std;
int c,t,n,x[N],d,y,s,num=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
       cin>>n>>d;int flag=1;
       for(int i=1;i<=n;i++)
       {
           cin>>x[i];
           if(i>=3&&x[i]-x[i-1]!=y) flag=0;
           y=x[i]-x[i-1];
       }
       if(flag)
       {
           int k=0;
           while(k*y<=d) k++;
           if(k<=2) cout<<0<<endl;
           else if(k>=4) cout<<0<<endl;
           else cout<<n-k<<endl;
       }
       else
       {
		   for(int i=n;i>=1;i--)
		   {
			   if(x[n]-x[i]<=d&&x[i]-x[1]<=d) s=i,num++;
		   }
		   if(num==2)
           {
			 int ans=0;
		    for(int i=1;i<s;i++)
		    {
				int p=upper_bound(x+1,x+1+n,x[i]+d)-x;
				ans+=(n-p+1);
			}
			cout<<ans<<endl;
           }
	       else cout<<0<<endl;  
	   }
    }
    return 0;
}

