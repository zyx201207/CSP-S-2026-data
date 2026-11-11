#include<bits/stdc++.h>
using namespace std;long long a[2000005],n,m,ans=1,ans_1,ans_2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	ans_1=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(m==n)
		{
			ans&=a[i];
		}
		if(m==1);
		{
			ans=max(ans,a[i]);
		}
	}
	if(m!=n&&m!=1)
	{
		ans=0x3f3f3f3f;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++){
			
				
				if((ans&a[j])>ans_1)
				{
					
					ans_1=(ans&a[j]);//cout<<(a[j])<<" ";
					ans_2=j;
				}
		}
			a[ans_2]=0;
			ans=ans_1;
			//cout<<ans_2<<" ";
			ans_1=0;
			
		}
	}
	cout<<ans;
}
