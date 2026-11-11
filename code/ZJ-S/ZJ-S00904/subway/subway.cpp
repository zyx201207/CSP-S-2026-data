#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+10;
//struct node{
//	int v,d;
//};
int c,n,m,z,q;
int w[N];
int t[N][501],dp[N],vis[N];
vector<int> a[N],d[N];
void f(int u,int fa,int fad){
	if(u==fa) return ;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i],dv=d[u][i];
		if(v==fa) continue;
		int sum=0;
		
		if(fad==dv){
			sum-=t[u][fad];
			sum+=t[v][dv];
		}
		else{
			sum+=t[u][dv];
			sum+=t[v][dv];
		}
		
		int fz=1;
		if(dp[v]>dp[u]+sum){
			dp[v]=dp[u]+sum;
			fz=0;
			memset(vis,0,sizeof(vis));
			vis[v]=1;
//			cout<<u<<" "<<v<<":"<<dp[v]<<"   ";
			f(v,u,dv);
		}
//		else cout<<u<<" "<<v<<" "<<dp[u]+sum<<"#   ";
		if(!vis[v]&&fz){
			vis[v]=1;
			f(v,u,dv);
		}
	}
	return ;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>z>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,aa,ab,tt;
		cin>>k>>aa>>tt;
		t[aa][i]=tt;
		for(int j=2;j<=k;j++){
			cin>>ab>>tt;
			a[aa].push_back(ab);
			a[ab].push_back(aa);
			d[aa].push_back(i);
			d[ab].push_back(i);
			t[ab][i]=tt;//Õ¾Ìüaaµ½Â·Ïßi
			aa=ab;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<a[i].size();j++){
//			cout<<a[i][j]<<","<<d[i][j]<<"   ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n\n";
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<t[i][j]<<"   ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int x,y;
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		dp[x]=0;
		f(x,-1,-1);
		cout<<"dp:";
		for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
		cout<<"\n\n";
		cout<<w[x]+w[y]+dp[y]<<"\n";
	}
	return 0;
}

/*
//Oct31==Dec25?
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



int fz=1;
		if(dp[v]>dp[u]+sum){
			dp[v]=dp[u]+sum;
			fz=0;
			vis[v]=1;
//			cout<<u<<" "<<v<<":"<<dp[v]<<"   ";
			f(v,u,dv);
		}
//		else cout<<u<<" "<<v<<" "<<dp[u]+sum<<"#   ";
		if(!vis[v]&&fz){
			vis[v]=1;
			f(v,u,dv);
		}



1:2,1
2:1,1   4,1   3,2
3:2,2   5,2
4:2,1
5:3,2

*/
