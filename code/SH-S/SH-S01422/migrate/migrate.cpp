#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000001;
long long c,t;
long long a[MAXN];
void small()
{
	while(t--)
	{
		int ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int l=1,r=2;
		while(r<=n)
		{
			if(r-l!=3)
			{
				int cnt=0;
				for(int i=l+1;i<r;i++)
				{
					if((a[i]-a[l]<=d)&&(a[r]-a[i]<=d))
					{
						cnt++;
					}
				}
				if(cnt==2)
				{
					ans++;
				}
			}
			if(r-l==3)
			{
				if(d>=a[r]-a[l])
				{
					ans++;
				}
				else
				{
					int cnt=0;
					for(int i=l+1;i<r;i++)
					{
						if((a[i]-a[l]<=d)&&(a[r]-a[i]<=d))
						{
							cnt++;
						}
					}
					if(cnt==2)
					{
						ans++;
					}
				}
			}
			r++;
			if(a[r]-a[l]>2*d)
			{
				l++;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
void aaa()
{
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		long long a1,a2,tmp;
		cin>>a1>>a2;
		for(int i=3;i<=n;i++)
		{
			cin>>tmp;
		}
		long long dis=a2-a1;
		//cout<<"dis="<<dis<<endl;
		if(d<2*dis)
		{
			cout<<0;
		}
		else if(d<3*dis)
		{
			if(n>=4)
			{
				cout<<n-3;
			}
			else
			{
				cout<<0;
			}
		}
		else if(d<4*dis)
		{
			if(n>=6)
			{
				cout<<n-5;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			long long num=d/dis;
			num*=2;
			num-=1;
			if(n>=num+1)
			{
				cout<<n-num+1;
			}
			else
			{
				cout<<0;
			}
			/*for(int i=5;i<=n/2+1;i++)
			{
				if(d<i*dis)
				{
					if(n>=2*i-2)
					{
						cout<<n-(2*i-3);
					}
					else
					{
						cout<<0;
					}
					break;
				}	
			}*/ 
		}
		cout<<endl;
	}
	return;
}
void bbb()
{
	/*while(t--)
	{
		int fst,lst;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		lst=upper_bound(a+1,a+n+1,d)-a;
		lst--;
		fst=
	}*/
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if((c<=10)&&(c!=0))
	{
		small();
	}
	else if((c==11)||(c==12)||(c==0))
	{
		aaa();
	}
	else if((c==13)||(c==14))
	{
		small();
	}
	else
	{
		small();
	}
	return 0;
}
