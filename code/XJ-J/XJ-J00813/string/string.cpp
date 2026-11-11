#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,sum,cnt=1,zs,ns,ncnt=1,sa[200005],ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		sa[i]=sum;
	}
	if(sum%2==1) ns=sum/2+1;
	else ns=sum/2;
	while(1)
	{
		if(sa[cnt]>ns){a[cnt]=0;break;}
		if(sa[n-ncnt+1]-ns<0){a[n-ncnt+1]=0;break;}
		if(a[cnt]>a[n-ncnt+1]) ans+=a[n-ncnt+1]*(c[cnt]!=c[n-ncnt+1]),a[cnt]-=a[n-ncnt+1],a[n-ncnt+1]=0,ncnt++;
		else if(a[cnt]<a[n-ncnt+1]) ans+=a[cnt]*(c[cnt]!=c[n-ncnt+1]),a[n-ncnt+1]-=a[cnt],a[cnt]=0,cnt++;
		else ans+=a[cnt]*(c[cnt]!=c[n-ncnt+1]),a[cnt]=0,a[n-ncnt+1]=0,cnt++,ncnt++;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
} 
