#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool A=1,B=1;
void dfs(int k,int s,int cnt){
	if(k==n+1){
		if(cnt==m) ans=max(ans,s);
		return;
	}
	if(cnt>m||s==0) return;
	dfs(k+1,s&a[k],cnt+1);
	dfs(k+1,s,cnt);
}
bool check(int x){
	while(x){
		if((x&1)==0) return 0;
		x>>=1;
	}
	return 1;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) B=0;
		if(!check(a[i])) A=0;
	}
	if(A){
		sort(a+1,a+1+n,cmp);
		ans=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else dfs(1,0x3f3f3f3f,0);
	cout<<ans;
	return 0;
}