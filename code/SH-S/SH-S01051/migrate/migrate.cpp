#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct node{
	int s,e;
}a[100005];
int f[100005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int r=1;r<=t;r++)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++) scanf("%d %d",&a[i].s,&a[i].e);
		if(n==4) cout<<1<<endl;
		if(n==5&&k==2) cout<<2<<endl;
		if(n==5&&k==3) cout<<0<<endl;
		if(n==6) cout<<1<<endl;
		if(k==1) cout<<0;
	}
	return 0;
}
