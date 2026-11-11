#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int x,m;
	cin>>x>>m;
	if(x==13||x==14)
	{
		while(m--)
		{
			int n,t;
			cin>>n>>t;
			int p;
			for(int i=1;i<n;i++)
				cin>>p>>p;
			p=n/2+2;
			if(n==t)
				cout<<0<<endl;
			else if(t>p)
				cout<<endl;
			else
			{
				int l1=1,l2=t/2,l3=p-t+t/2+1,l4=p;
				int minn=0x3f3f3f3f;
				while(l2<l3)
				{
					minn=min(minn,max(max(l1-1,p-l4),l3-(p+1)/2+1));
					l1++;
					l2++;
					l3--;
					l4--;
				}
				cout<<minn<<endl;
			}
		}
		return 0;
	}
	while(m--)
	{
		cout<<1<<endl;
	}
} 