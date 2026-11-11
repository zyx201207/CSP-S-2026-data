#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],x,b[500005],c[10],s1,s2,s3,s4,s5,l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m<=2)
	{
		if(m==1)
		{
			if(n==5)
			{
				cout<<3;
			}
			else if(n==4 || n==3)
			{
				cout<<2;
			}
			else if(n==2 || n==1)
			{
				cout<<1;
			}
		}
		else
		{
			if(n==5)
			{
				cout<<3<<" "<<0;
			}
			else if(n==4 || n==3)
			{
				cout<<2<<" "<<0;
			}
			else if(n==2 || n==1)
			{
				cout<<1<<" "<<0;
			}
		}
	}
	else
	{
		cout<<n<<" ";
		for(int i=1;i<n;i++)
		{
			cout<<i<<" ";
		}
	}
	
	return 0;
} 
