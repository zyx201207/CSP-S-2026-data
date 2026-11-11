#include<bits/stdc++.h>
#include<cmath>
#define int long long
using namespace std;
//RRIM算法 
//只考虑换乘2次 
int c,n,m,d,q,wi[1000],ti[100],x,r,k,ans,cnt1,cnt2,vis[100][2],tr[1000],g[1000][1000],t[1000],maxn;//g存储地铁经过站，t存储站有哪些地铁 
int find(int st,int ed){
	for(int i=1;i<=n;i++){
		if(t[st][i]!=0 and t[ed][i]!=0){
			ans=g[st][st][i]]+g[i][t[ed][i]];
			cout<<ans<<endl;
			return 0; 
		}
		else{
			if(t[st][i]!=0)  vis[st][cnt1]=i,cnt1++;
			if(t[ed][i]!=0) vis[ed][cnt2]=1,cnt2++;
		}
	}
}
int main(){
		cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wi[i];
	}
	for(int i=1;i<=n;i++){//线路 
		cin>>k;
		maxn=max(maxn,k);
		for(int j=1;j<=k;j++){//第几站 
			int a,ts;//a是站点，ts是时间 
			cin>>a>>ts;
			g[i][j]=ts;
			t[a][i]=j;
		}}
	for(int i=1;i<=q;i++){
		cin>>x>>r;
		else{
			find(x,y);
		}
	}
	return 0;
}
