#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],q[200005],ans=-1;
bool s[200005],flag=1,tmp,flag2=1;
bool cmp(int a,int b){
	return a>b;
}
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=x*res;
		x=x*x,y>>=1;
	}
	return res;
}
void dfs(int x,int last){
	if(x==m){
		int cnt=q[1];
		for(int i=2;i<=m;i++) cnt&=q[i];
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!s[i]&&i>last&&a[i]>=ans){
			s[i]=true;
			q[x+1]=a[i];
			dfs(x+1,i);
			s[i]=false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;flag2&=(qpow(2,log2(n))==n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) tmp=a[i];
		else tmp&=a[i];
		if(flag){
			int cnt=log2(a[i]+1);
			flag&=(qpow(2,cnt)==a[i]+1);
		}
		flag2&=(a[i]==i-1);
	}
	sort(a+1,a+n+1,cmp);
	if(n==m) return cout<<tmp,0;
	if(flag) return cout<<a[m],0;
	if(flag2){
		ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		return cout<<ans,0;
	}
	if(m==1) return cout<<a[1],0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
}
/*
5 3
3 1 7 63 255
4 2
3 15 12 12
*/