//qwq，真的力竭了，为什么不对吗~~T-T
//我真的尽力了T-T 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long l,r,lenth=1,ans;
int a[50050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=i-1;
		r=i+1;
		long long cz=0;
		long long cl=0,cr=0;
		lenth=1;
		while(1)
		{
			
			cr=abs(a[i]-a[r]);
			cl=abs(a[i]-a[l]);
			if(cr<=cl && r<=n)
			{
				if(cz+cr<=m)
				{
					cz+=cr;
					lenth++;
					r++;	
				}
				else
				{
					break;
				}
		
			}
			else
			{
				if(cz+cl<=m && l>=1)
				{
					cz+=cl;
					lenth++;
					l--;
				}
				else
				{
					break;
				}
    		}
    		if(lenth>ans)
			{
				ans=lenth;
			}
		}
		
		
	
	}
	cout<<ans<<endl;
	//评测机先生，求您了~~ 
	return 0;
} 




