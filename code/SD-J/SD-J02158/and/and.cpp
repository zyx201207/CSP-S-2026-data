#include<bits/stdc++.h>
using namespace std;
int a[200005],p[35];
int n,m,flag1=1,ma;
bool cmp(int a,int b)
{
	return a>b;
}
int f(int a){
	int ans=1;
	for(int i=1;i<=a;i++){
		ans*=2;
	}
	return ans;
}
void dfs(int deep,int cnt,int num){
	if(deep==n){
		if(cnt==m) ma=max(ma,num);
		return ;
	}
	if(num==-1){
		dfs(deep+1,cnt+1,a[deep+1]);
		dfs(deep+1,cnt,-1)
	}else{
		dfs(deep+1,cnt+1,num&a[deep+1]);
		dfs(deep+1,cnt,num);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		p[i]=f(i)-1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=p[i]) flag1=0;
	} 
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i]; 
		}
		cout<<ans;
	}else if(flag1){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}else{
		dfs(0,0,-1);
		cout<<ma;
	}
	return 0;
}
