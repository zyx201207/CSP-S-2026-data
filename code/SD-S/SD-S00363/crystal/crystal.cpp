#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,aa,bb=-1,cnt;
const int MAXN=500005;
long long a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//sum+=a[i];
	}
	//sort(a+1,a+1+n);
	//sum=sum/n;
	int x=a[((n+1)/2)];
	if(n%2==0) x=a[n/2+1];
	//cout<<x<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x) bb++;
	}
	for(int i=floor(n/2);i>=1;i--)
	{
		aa+=x-a[i];
		//cout<<aa<<" ";
		if(aa>m) break;
		if(x-a[i]<m)cnt++;
	}
	cout<<cnt+bb+1;
	return 0;
} 
