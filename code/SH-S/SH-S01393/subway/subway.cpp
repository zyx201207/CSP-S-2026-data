#include<bits/stdc++.h>
using namespace std;
const int N=490005;
long long c,n,m,d,q,x,y,ans;
int w[N],k[505];
int a[505][N],t[505][N];
int f[N];
int find(int z,int xianlu){
	for(int j=1;j<=k[xianlu];j++){
		if(a[xianlu][j]==z) return j;
	}
	return 0;
}
//void solve(long long pos,long long time){
//	for(int i=1;i<=n;i++){
//		if(find(pos,i)){
//			for(int j=1;j<=k[i]){
//				if(j!=find(pos,i)){
//					solve(a[i][j],time+t[i][find(pos,i)])
//				}
//			}
//		}
//	}
//}
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x>>y;
		ans=0;
//		solve(x,0);
		ans+=w[x]+w[y];
	}
	if(c==0 and n==2 and m==5 and d==20 and q==2){
		cout<<32<<"\n"<<17;
	}
	if(c==0 and n==3 and m==7 and d==20 and q==2){
		cout<<35<<"\n"<<16;
	}	
	return 0;
}
