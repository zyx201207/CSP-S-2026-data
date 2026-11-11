#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[50005],x,y;
long long w[50005],a[505][50005],t[505][50005];
long long minn=LLONG_MAX;
bool vis[505][50005];
int pd(int s,int l){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(i==l) break;
			if(a[i][j]==s){
				if(vis[i][a[i][j]]) break;
				else return i;
			}
		}
	}
	return 0;
}
void bfs(int s,int e,int l,int cnt){
	if(s==e){
		if(minn>cnt) minn=cnt;
		return;
	}
	for(int j=1;j<=k[l];j++){
		if(vis) continue;
		int l2=pd(a[l][j],l);
		vis[l][s]=1;
		bfs(a[l][j],e,l,cnt+t[l][a[l][j]]);
		if(l2) bfs(a[l2][j],e,l2,cnt+t[l2][a[l2][j]]);
		vis[l][s]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
		}
	}
	for(int qu=1;qu<=q;qu++){
		cin>>x>>y;
		long long cnt=w[x]+w[y],l;
		minn=LLONG_MAX;
		for(int i=1;i<=n;i++){
			if(t[i][x]!=0&&t[i][y]!=0){
				cnt=cnt+t[i][x]+t[i][y];
				minn=min(minn,cnt);
			}
			if(t[i][x]!=0) l=i;
		}
		bfs(x,y,l,0);
		cout<<minn<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

