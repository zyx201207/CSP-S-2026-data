#include<bits/stdc++.h>
using namespace std;
long long  n,a[200001],tt,ans=0;
int f[200001],p[10000000];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		f[i]=c[i]-'0';
		for(int j=1;j<=a[i];j++) p[tt+j]=f[i];
		tt+=a[i];
	}
	long long m=tt;
	tt/=2;
	for(int i=1;i<=tt;i++)
		if(p[i]!=p[m-i+1]) ans++;
	cout<<ans;
	return 0;
}