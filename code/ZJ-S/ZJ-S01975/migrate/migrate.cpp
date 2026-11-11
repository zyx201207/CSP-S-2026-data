#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,nw,cost,num;
int ans;
int n,a[2000050],d;
void dfs(int x,int y,int cst){
	if(cst>cost) return;
	if(x==y){
		num++;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,cst+1);
		}
		else{
			break;
		}
	}
}
void f(int x,int y){
	nw=x,cost=1;
	for(int i=x;i<y;i++){
		if(i<y&&a[i+1]-a[i]>d) return;
		if(a[i+1]-a[nw]>d){
			nw=i;
			cost++;
		}
	}
	
	num=0;
	dfs(x,y,0);
	if(num==2){
		ans++;
	}
}
void solve1(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			f(j,i);
		}
	}
	cout<<ans;
}
void solve2(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[2]-a[1];
	d/=k;
	if(d<=1) cout<<0;
	else{
		int g=d*2-1;
		cout<<max(0ll,n-g);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12) solve2();
		else solve1();
		cout<<"\n";
	}
	return 0;
}

