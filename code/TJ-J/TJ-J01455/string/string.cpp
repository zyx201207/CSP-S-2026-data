#include<bits/stdc++.h>
using namespace std;
long long ans;
char c[200010];
int a[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	
	long long chazhi=0;
	for(int i=1,l=n;i<=l;)
	{
		if(a[i]==a[l])
		{
			if(c[i]!=c[l])
			{
				ans+=a[i];
				i++;
				l--;
			}
			else
			{
				i++;
				l--;
			}
		}
		else if(a[i]!=a[l])
		{
			chazhi=max(a[i],a[l]);
			if(a[i]<a[l])
			{
				for(;chazhi!=0;i++)
				{
					if(c[i]==c[l])
					{
						if(chazhi>=a[i]) chazhi-=a[i];
						else if(chazhi<a[i])
						{
							a[i]-=chazhi;
							i++;
						}
						else
						{
							chazhi=0;
							i++;
							l--;
						}
					}
					else
					{
						if(chazhi==a[i])
						{
							ans+=chazhi;
							i++;
							l--;
							chazhi=0;
						}
						else if(chazhi>a[i])
						{
							ans+=a[i];
							chazhi-=a[i];
//							cout<<ans<<" "<<chazhi<<endl;
						}
						else
						{
							ans+=chazhi;
							a[i]-=chazhi;
							chazhi=0;
							l--;
						}
					}
					if(i+1==l||i==l)
					{
						cout<<ans;
						return 0;
					}
				}
			}
			else if(a[i]>a[l])
			{
				for(;chazhi!=0;l--)
				{
					if(c[i]==c[l])
					{
						if(chazhi>a[l]) chazhi-=a[l];
						else if(chazhi<a[l])
						{
							a[l]-=chazhi;
							i++;
						}
						else
						{
							chazhi=0;
							i++;
							l--;
						}
					}
					else
					{
						if(chazhi==a[l])
						{
							ans+=chazhi;
							i++;
							l--;
							chazhi=0;
						}
						else if(chazhi>a[l])
						{
							ans+=a[l];
							chazhi-=a[l];
//							cout<<ans<<" "<<chazhi<<endl;
						}
						else
						{
							ans+=chazhi;
							a[l]-=chazhi;
							chazhi=0;
							i++;
						}
					}
					if(i+1==l||i==l)
					{
						cout<<ans;
						return 0;
					}
				}
			}
		}
//		cout<<ans<<" "<<chazhi<<endl;
	}
	cout<<ans;
//4
//3 a
//3 b
//2 c
//3 d
	return 0;
}
