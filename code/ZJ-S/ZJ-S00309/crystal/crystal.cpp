#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
//14:47 
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
const int N=5e5+5;
LL m;
int n; 
LL a[N];
int main()
{
	FRE
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	LL ans=1,cnt=0;
	LL l=1,r=1;
	while(r<=n)
	{
		int len=r-l+1;
		r++;
		cnt+=len*(a[r]-a[r-1]);
		while(cnt>m)
		{
			cnt-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
