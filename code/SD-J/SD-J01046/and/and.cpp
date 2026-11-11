#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N],s[N],f[N];
//dfs表示:到第id个数,选了ch个,价值多少 
void dfs(int id,int ch,int val){
	if(ch>m) return ;
	if(id==n+1){
		if(val>ans&&ch==m) ans=val;
		return ;
	}
	if(ch==0){
		dfs(id+1,ch,val);
		dfs(id+1,ch+1,a[id]);
	}else{
		dfs(id+1,ch,val);
		dfs(id+1,ch+1,val&a[id]);
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		int k=log2(a[i]+1);
		if((1ll<<k)!=a[i]+1) return false;
	}
	return true;
}
bool check2(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[1]) return false;
	}
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res=max(res,a[i]);
		}
		cout<<res<<"\n";
		return 0;
	}
	if(m==n){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res=res&a[i];
		}
		cout<<res<<"\n";
		return 0;
	}
	if(m==2&&n<=2000){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				res=max(res,a[i]&a[j]);
			}
		}
		cout<<res<<"\n";
		return 0;
	}
	if(check()){
		sort(a+1,a+1+n,greater<>());
		int res=a[1];
		for(int i=2;i<=m;i++){
			res=res&a[i];
		}
		cout<<res<<"\n";
		return 0;
	}
	if(check2()){
		cout<<a[1]<<"\n";
		return 0;
	} 
	cout<<0<<"\n";
	return 0;
}
