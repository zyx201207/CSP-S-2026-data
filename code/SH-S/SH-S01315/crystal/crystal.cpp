#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,c[500005],q[500005],maxn; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
		q[i]=q[i-1]+c[i];
	}
	q[1]=0;
	long long ans=0,len=1;
	for(int i=1;i<=n-1;i++)
	{
		ans+=len*c[i];len++;
		if(ans<=m)
		{
			maxn=max(maxn,len);
		}
		else
		{
			while(ans>m&&len>0)
			{
				len--;
				ans-=(q[i]-q[i-len+1]);
			}
			maxn=max(maxn,len);
		}
	 } 
	 cout<<maxn<<"\n";
	return 0;
}

