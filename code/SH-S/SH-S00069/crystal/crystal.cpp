#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long d[500005];
bool check(int x)
{
	int las=n-x+1;
	long long del=0;
	long long ch=1e18+5;
	for(int i=1;i<=x;i++)
	{
//		cout<<"del:"<<del<<" a[x]:"<<a[x]<<" a[i]:"<<a[i]<<endl;
		del+=(a[x]-a[i]);
	}
//	cout<<del<<endl; 
	ch=min(ch,del);
	for(int i=2;i<=las;i++)
	{
		del=del-(a[i+x-2]-a[i-1])+d[i+x-1]*(x-1);
		ch=min(ch,del);
	}
//	cout<<ch<<endl;
	if(ch<=m) return 1;
	else return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	int l=1,r=n;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
//		cout<<l<<" "<<mid<<" "<<r<<endl;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
