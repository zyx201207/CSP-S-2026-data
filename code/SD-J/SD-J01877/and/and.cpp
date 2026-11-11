#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	if(n==m){
		long long s=0,b;
		cin>>s;
		for(int i=2;i<=n;i++)
		{
			cin>>b;
			s&=b;
		}
		cout<<s;
		return 0;
	}
	if(m==1){
		long long b,s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>b;
			if(b>s)
			s=b;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2){
		long long s=0;
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
				if(s<(a[i]&a[j]))
					s=a[i]&a[j];
		cout<<s;
		return 0;
	}
	if(m==n-1){
		long long s=0,f;
		int r;
		for(int k=1;k<=n;k++)
		{
			if(k==1) r=2;
			else r=1;
			f=a[r];
			for(int i=1;i<=n;i++)
			{
				if(i!=k&&i!=r)
					f&=a[i];
			}
			if(s<f) s=f;
		}
		cout<<s;
		return 0;
	}
	if(a[1]!=0){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(a[1]==0&&a[n]==n-1){
		for(int i=n-1,j=1;j<=m;i--,j++)
			a[n]&=a[i];
		cout<<a[n];
		return 0;
	}
	return 0;
}
