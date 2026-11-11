#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N],ans=0;
bool check(long long i,long long m)
{
	m-=a[i]*i-s[i]-i+1;
//	cout<<m<<" ";
	return m>=0;
}
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
		cin>>a[i];
   }
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)
   {
		s[i]=s[i-1]+a[i];
   }
    for(int i=1;i<=n;i++)
	{
   		int l=1,r=n;
   		int mid;
   		while(l<r)
   		{
			mid=(l+r)>>1;
	   		if(check(mid,m))
	   		{
	   			if(mid>ans)
	   			{
	   				ans=mid;
				}
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		
   	}
   	cout<<ans;
    return 0;
}
//luogu ruizhe2013
//sha ye bu hui fei le ming nian chu san zai lai
