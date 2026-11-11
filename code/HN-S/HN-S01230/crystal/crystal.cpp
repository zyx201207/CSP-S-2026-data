#include<bits/stdc++.h>
using namespace std;
int n,m,cnt =0,ans=0,g=0,t=0;
int a[100000009];
int b[100000009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		b[k-1]=a[k]-a[k-1];
	}
	
	for(int o=1;o<n;o++)
	{
			cnt+=b[o];
			ans++;
			if(cnt>=m)
			{
				cnt-=b[o];
				break;
				t = 1;
			}
		
			
	}
	if(t==1)
		cout<<ans;
	else
		cout<<ans+1;
	return 0;
}
