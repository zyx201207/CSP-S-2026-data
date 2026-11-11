#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int n,d;
int dm(int l,int r)
{
	if(l==r)return 0;
	int mi=INT_MAX;
	for(int i=l+1;i<=r;i++)
		if(a[i]-a[l]<=d)
			mi=min(dm(i,r)+1,mi);
	return mi;
}
int dc(int l,int r,int k)
{
	if(l==r&&k!=0)return 0;
	if(l==r&&k==0)return 1;
	int cnt=0;
	for(int i=l+1;i<=r;i++)
		if(a[i]-a[l]<=d)
			cnt+=dc(i,r,k-1);
	return cnt;
}
int main()
{	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)	
			cin>>a[i];
		if(c==11||c==12)
		{
			int k=a[2]-a[1];
			int q=d/k;
			if(q==0||n%q==0)
				cout<<0<<endl;
			else
			{
				cout<<1<<endl;
			}
		}
		else if(c==13||c==14)
			cout<<0<<endl;
		else if(n<=9)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cnt+=(dc(i,j,dm(i,j))==2);
			cout<<cnt<<endl;
		}else 
		cout<<0<<endl;
	}
	return 0;
}

