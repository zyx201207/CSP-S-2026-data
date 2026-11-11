#include<bits/stdc++.h>
#define int long long
const int N=1e6+5;
using namespace std;
int a[N];
int vis[N];
int ans=0;
int n,m;
int maxx(int a,int b){
	if(a>b)return a;
	else return b; 
}
void dfs(int x,int h){
	if(x>n){
		if(h<=m){
			int cnt=0;
			for(int i=1;i<=n;i++){
				vis[a[i]]++;
			}
			for(int i=1;i<=n;i++){
				cnt=maxx(cnt,vis[a[i]]);
			}
			for(int i=1;i<=n;i++){
				vis[a[i]]=0;
			}
			ans=maxx(ans,cnt);
		}
		return;
	}
	if(h>m)return;
	for(int i=0;i<=m-h;i++){
		a[x]+=i;
		dfs(x+1,h+i);
		a[x]-=i;
	}
	return;
}
//暴力搜索 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//特殊性质A
	bool b=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i)b=false;
	}
	if(b){
		int f=m;
		int ansA=1;
		int d=1;
		while(f>=d){
			f-=d;
			d++;
			ansA++;
		}
		cout<<min(ansA,n)<<endl;
		return 0;
	}
	//特殊性质B
	int b1=true;
	int di=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=di)b1=false;
	} 
	if(b1){
		int f=m;
		int ansB=1;
		int d=di;
		while(f>=d){
			f-=d;
			d+=di;
			ansB++;
		}
		cout<<min(ansB,n)<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans; 
	return 0;
}