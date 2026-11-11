#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1000000000005],b;
void msum(int x,int y)
{
	if((x-1)*x/2<=y)
	{
		cout<<x;
		return;
	}
	else{
		msum(x-1,y);
	}
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i) b++;
		if(b==n)
		{
			msum(n,m);
			return 0; 
		}
		if(m==0)
		{
			cout<<"1";
		}
		if(m==1)
		{
			cout<<'2';
		}
	}
		
	
	return 0;
}
