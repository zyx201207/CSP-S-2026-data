#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n=0,m=0,k=0,x=0,y=0,z=0;
int a[200005]={0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		k=max(k,a[i]);
		if(a[i]==1)x++;
		if(a[i]==2)y++;
		if(a[i]==3)z++;
	}
	if(n<=20)
	{
		int b[21]={0};
		int k=0;
		while(b[n]==0)
		{
			b[0]++;
			if(b[0]==2)
			{
				b[0]=0;
				int t=1;
				while(b[t]==1)
				{
					b[t]=0;
					t++;
				}
				b[t]=1;
			}
			int num=0;
			int ans=0;
			for(int i=0;i<n;i++)
			{
				num+=b[i];
			}
			if(num!=m)
			{
				continue;
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(b[i]==1)
					{
						ans=a[i];
					}
				}
				for(int i=0;i<n;i++)
				{
					if(b[i]==1)
					{
						ans&=a[i];
					}
				}
			}
			k=max(ans,k);
		}
		cout<<k<<endl;
	}
	else
	{
		if(m==1)
		{
			int mx=0;
			for(int i=0;i<n;i++)
			{
				mx=max(mx,a[i]);
			}
			cout<<mx;
		}
		else
		{
			if(m==n)
			{
				int ans=a[0];
				for(int i=0;i<n;i++)
				{
					ans&=a[i];
				}
				cout<<ans;
			}
			else
			{
				if(m==2)
				{
					int mx=0;
					for(int i=0;i<n;i++)
					{
						for(int j=i+1;j<n;j++)
						{
							mx=max(mx,a[i]&a[j]);
						}
					}
					cout<<mx;
				}
				else
				{
					if(k==3)
					{
						if(z>=m)
						{
							cout<<"3";
						}
						else if(z+y>=m)
						{
							cout<<"2";
						}
						else if(z+x>=m)
						{
							cout<<"1";
						}
						else
						{
							cout<<"0";
						}
					}
					else
					{
						sort(a,a+n,cmp);
						cout<<a[m-1];
					}
				}
			}
		}
	}
	return 0;
}
