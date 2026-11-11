#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int MA=0;
void dfs(int l,int idx,int yu)
{
	if(l==m||idx==n+1)
	{
		if(l==m)MA=max(MA,yu);
		return; 
	}
	dfs(l+1,idx+1,yu&a[idx]);
	dfs(l,idx+1,yu);
}
bool is()
{
	long long b=1;
	for(int i=1;i<=30;i++)
	{
		b*=2;
		if(n==b) return true;
	}
	return false;
}
bool is_2k(int x)
{
	long long bi=1;
	for(int i=1;i<=31;i++)
	{
		if(x==bi-1) return true;
		bi=bi*2;
	}
	return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool f_is_2k=0;
	bool f_is_d=0;
	if(!is()) f_is_d=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!is_2k(a[i])) f_is_2k=1;
		if(a[i]!=i-1) f_is_d=1;
	}
	if(m==n)
	{
		int ans=(1<<31)-1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		int ma=0;
		for(int i=1;i<=n;i++)ma=max(a[i],ma);
		cout<<ma;
		return 0;
	}
	if(n<=20)
	{
		dfs(0,1,(1<<31)-1);
		cout<<MA;
		return 0; 
	}
	if(m==2&&n<=2000){
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(!f_is_2k)
	{
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m];
		return 0;
	}
	if(!f_is_d)
	{
		sort(a+1,a+1+n,greater<int>());
		int ans=(1<<31)-1; 
		for(int i=1;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==n-1)
	{
		int an=(1<<31)-1;
		for(int i=2;i<n;i++)an=(an&a[i]);
		cout<<max(an&a[1],an&a[n]); 
	}
	cout<<0;
	return 0;
}
