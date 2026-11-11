#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[200100],n;
long long ans;
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		int skk=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=skk;
		a[l]-=skk;
		a[r]-=skk;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
//		cout<<l<<" "<<r<<'\n';
	}
	cout<<ans;
	return 0;
 } 
