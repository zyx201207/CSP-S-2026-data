#include<bits/stdc++.h>
using namespace std;
int a[200010],mx,n,m;
int p[31];
void dfs(int x,int res,int cnt){
	if(cnt==m){
		mx=max(mx,res);
		return;
	}
	if(x==n) return;
	for(int i=x+1;i<=n;i++)
		dfs(i,res&a[i],cnt+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++)
		p[i]=p[i-1]*2;
	for(int i=0;i<=30;i++)
		p[i]--;
	bool flag=1,flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int pos=lower_bound(p,p+n+1,a[i])-p;
		if(p[pos]!=a[i]) flag=0;
		if(a[i]!=i-1) flag1=0;
	}
	sort(a+1,a+n+1,greater<int>());
	if(flag) mx=a[m];
	else if(flag1) mx=n-m;
	else dfs(0,a[1],0);
	cout<<mx;
	return 0;
}//65
