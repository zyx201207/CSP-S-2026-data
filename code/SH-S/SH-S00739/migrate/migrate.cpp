#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x,s,j,las,ans;
const long long N=100000010;
bool a[200000020];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	if(c==0||c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=0;i<n;i++)
			{
				if(i==0)
				{
					cin>>s;
				}
				else if(i==1)
				{
					cin>>j;
					j=j-s;
				} 
				else
				{
					cin>>x;
				}
			}
			d=d/j;
			if(d==0||d==1)
			{
				cout<<"0\n";
			}
			else if(n-2*d+1>=0)
			{
				cout<<n-2*d+1<<"\n";
			}
			else
			{
				cout<<"0\n";
			}
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=0;i<n;i++)
			{
				cin>>x;
				if(i==0)
				{
					s=x+N;
				}
				if(i==n-1)
				{
					las=x+N;
				}
				a[x+N]=1;
			}
			for(int i=s;i<=las-2*d+1;i++)
			{
				if(a[i]==1&&a[i+2*d-1]==1&&a[i+d]==1&&a[i+d-1]==1)
				{
					ans++;
				}
			}
			if(d==0||d==1)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<ans<<"\n";
			}
		}
	}
	
	return 0;
}
