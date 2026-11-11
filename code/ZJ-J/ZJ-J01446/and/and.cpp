#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=pow(2,30)-1;
int n,m,a[N],s;
void dfs(int now,int cnt,int ans){
	if(now>n){
		if(cnt!=m) return;
		s=max(s,ans);
		return;
	}
	dfs(now+1,cnt,ans);
	dfs(now+1,cnt+1,ans&a[now]);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,INF);
		cout<<s;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
		cout<<s;
		return 0;
	}
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			f=0;
			break;
		}
	}
	int k=0;
	for(int i=0;i<=30;i++){
		if(pow(2,i)==n){
			k=i;
			break;
		}
	}
	if(f&&k){
		int c=INF;
		for(int i=1;i<=m;i++){
			int x=n+1-i;
			c&=a[x];
		}
		cout<<c;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	if(a[1]<4){
		cout<<a[m];
		return 0;
	}
	int c=INF;
	for(int i=1;i<=m;i++){
		c&=a[i];
	}
	cout<<c;
	return 0;
}
