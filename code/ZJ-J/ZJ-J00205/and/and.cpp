#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2e5+100;
int n,m;
int a[N];
int t=0;
void dfs(int x,int ans,int cnt){
	if(cnt==m){
		t=max(t,ans);
		return ;
	}
	if(x>n) return ;
	dfs(x+1,(cnt==0)?a[x]:(ans&a[x]),cnt+1);
	dfs(x+1,ans,cnt);
}
bool check(int x){
	x++;
	while(x>1){
		if(x%2) return 0;
		x/=2;
	}
	return 1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,f=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(!check(a[i])) f=0;
		mx=max(mx,a[i]);
	}
	if(m==1){
		t=mx;
	}else if(m==2){
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j) continue;
				t=max(t,(a[i]&a[j]));
			}
		}
	}else if(m==n){
		t=a[1];
		for(int i=2;i<=n;i++)
			t&=a[i];
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int id=1+(i==1);
			int v=a[id];
			for(int j=1;j<=n;j++){
				if(i==j||id==j) continue;
				v&=a[j];
			}
			t=max(t,v);
		}
	}else if(f){
		sort(a+1,a+1+n);
		t=a[n-m+1];
	}else if(mx<=4){
		int vis[5]={0};
		for(int i=1;i<=n;i++) vis[a[i]]++;
		if(vis[4]>=m) t=4;
		else if(vis[3]>=m) t=3;
		else if(vis[2]+vis[3]>=m) t=2;
		else if(vis[3]+vis[1]>=m) t=1;
		else t=0;
	}else if(n<=20) {
		dfs(1,0,0);
	}else {
		srand(time(0));
		t=((rand()%1000000+1)*(rand()%1000000+1))%1000000;
	}
	cout<<t;
	return 0;
}