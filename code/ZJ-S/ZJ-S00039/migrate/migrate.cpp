#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,a[2000005],qly;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		qly=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			long long pos=upper_bound(a+1,a+1+n,a[i]+d)-a;
			//cout<<pos<<"\n";
			if(pos!=n+1)
			{
				if(pos-i-1==2)
				{	
//					if(a[pos-1]+d>=a[pos])
//					{
//						qly++;
//					}
					bool flag=true;
					for(int j=i;j<=pos-1;j++)
					{
						if(a[i]+d<a[j])
						{
							flag=false;
							break;
						}
					}
					if(flag==true)
					{
						if(a[pos-1]+d>=a[pos]&&((pos+1<=n&&a[pos-1]+d<a[pos+1])||pos+1>n))
						{
							qly++;
						}
						int k=1;
						while(a[pos-1+k]+d>=a[pos+k]&&((a[pos-1+k]+d<a[pos+k+1]&&pos+k+1<=n)||pos+k+1>n))
						{
							if(pos+k+1>n)
							{
								qly++;
								break;
							}
							k++;
							qly++;
						}
					}
				}
			}
		}
		cout<<qly<<"\n";	
	}
	return 0;
}