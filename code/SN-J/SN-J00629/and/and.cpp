//王彦龙 庆安初级中学 SN-J00629
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;

int n,m;
int a[N];
bool vis[N];

bool cmp(int a,int b){
	return a>b;
}

int cel(double x){
	return ceil(x);
}

int ans=0;
void dfs(int pos,int sum,int res){
	
	if(pos>n && sum!=m) return;
	
	if(sum==m){
		ans=max(ans,res);
		return;
	}
	
	if(sum+n-pos+1<m) return;
	
	vis[pos]=1;
	dfs(pos+1,sum+1,res&a[pos]);
	
	vis[pos]=0;
	dfs(pos+1,sum,res);
}

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	int mx=0;
	bool flagb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flagb=0;
		mx=max(mx,1ll*cel(log2(a[i])));
	}
	
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	
	if(m<=20){
		dfs(1,0,(1<<mx)-1);
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+1+n,cmp);
	if(flagb){
		ans=n-1;
		for(int i=1;i<=m;i++) ans&=a[i];
		cout<<ans;
	}
	else{
		cout<<a[m];
	}
	
	return 0;
	
}
