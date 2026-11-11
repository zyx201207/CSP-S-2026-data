#include<bits/stdc++.h>
using namespace std;
int n,m,ans,s,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
 	for(int i=1;i<=n;i++)cin>>a[i];
 	sort(a+1,a+n+1);
 	if(m==1){cout<<a[n];return 0;}
 	if(m==n){
 		s=a[1];
 		for(int i=2;i<=n;i++)
 		 s=s&a[i];
 		cout<<s;
 		return 0;
	}
	if(m==2)
	{
		ans=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=a[i]&a[j];
				if(s>ans)ans=s;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m>2){
		s=a[n];
		for(int i=n-1;i>n-m;i--)s=s&a[i];
		cout<<s;
		return 0;
	}
	return 0; 
 } 
