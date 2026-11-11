#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,idx,maxx,minn;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int cnt,int t,int x){
	if(cnt==m){
		ans=max(ans,t);
		return ;
	}
	if(x>=n) return ;
	dfs(cnt+1,t&a[x],x+1);
	dfs(cnt,t,x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(maxx<=4){
		int cnt=0; 
		for(int i=1;i<=n;i++){
			if(a[i]==4) cnt++;
		}
		if(cnt>=m){
			cout<<4;
			return 0;
		}
		cnt=7;
		for(int i=1;i<=m;i++){
			if(a[i]==4) continue;
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	dfs(0,0xffffffff,1);
	cout<<ans;
	return 0;
}
