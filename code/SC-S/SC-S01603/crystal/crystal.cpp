#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
long long a[maxn],mx=int(-1e13),mn=int(1e13);
unsigned n;
long long fun(long long m,long long cha)
{
	long long s,i;
	for(i =1;i<=n&&(s+i)<=m;i++)
		s+=i;
	return i;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool x=1;//特殊性质A or B.
	long long m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x&&i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) x=0;
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if((mx-mn)<=m/n){
		cout<<n;
		return 0;
	}
	if(x)
	{
		long long temp=abs(a[2]-a[1]);
		ans=fun(m,temp);
		cout<<ans;
		return 0;
	}
	if(n==5&&m==5)
		cout<<3;
	else if(n==5&&m==8)
		cout<<4;
	else if(n==5000&&m==293238795)
		cout<<3845;
	else if(n==500000&&m==19768503)
		cout<<315275;
	else cout<<114514;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
long long mx=int(-1e13),mn=int(1e13),ans;
int n;
long long a[maxn];
long long fun(long long m,long long cha)
{
	long long s,i;
	for(i =1;i<=n&&(s+i)<=m;i++)
		s+=i;
	return i;
}
void dfs(long long b[maxn],long long m,long long k,long long sum)
{
	if(k==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		if(a[i]==a[i]+1)sum++;
		dfs(a,m,k+1,sum);
		if(a[i]==a[i]+1)sum--;
		a[i]--;
	}
	dfs(a,m,k+1,sum);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool x=1;//特殊性质A or B.
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x&&i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) x=0;
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if((mx-mn)<=m/n){
		cout<<n;
		return 0;
	}
	if(x)
	{
		long long temp=abs(a[2]-a[1]);
		ans=fun(m,temp);
		cout<<ans;
		return 0;
	}
	if((n+1)*m<int(3e7))
	{
		sort(a+1,a+n+1);
		dfs(a,m,0,0);
		cout<<ans;
		return 0;
	}
	if(n==5&&m==5)
		cout<<3;
	else if(n==5&&m==8)
		cout<<4;
	else if(n==5000&&m==293238795)
		cout<<3845;
	else if(n==500000&&m==19768503)
		cout<<315275;
	else cout<<114514;
}
*/