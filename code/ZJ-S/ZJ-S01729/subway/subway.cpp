#include<bits/stdc++.h> 
using namespace std;
long long w[505],px[505],ps[505],xk[505],xa[505][505][2],sx[505],ss[505][505][2];
//struct node{
//	long long k;
//	long long a[505][2];
//}x[505];
//struct Node{
//	long long x;
//	long long s[505];
//}s[505];
//long long dfs(long long t,long long x,long long y){
//	if(x==y) return t;
//	long long minn=10000000;
//	for(long long i=0;i<s[x].x;i++){
//		if(px[i]==0){
//			px[i]=1;
//			for(long long j=0;j<x[s[x].s[i]].k;j++){
//				if(ps[x[s[x].s[i]].a[j][0]]==0){
//					ps[x[s[x].s[i]].a[j][0]]=1;
//					minn=min(minn,dfs(t+x[s[x].s[i]].a[j][1]+x[s[x[s[x].s[i]].a[j][0]].s[i]].a[j][1],x[s[x].s[i]].a[j][0],y))
//					ps[x[s[x].s[i]].a[j][0]]=0;
//				}
//			}
//			px[i]=0;
//		}	
//	}
//	return minn;
//}
long long dfs(long long t,long long x,long long y){
	if(x==y) return t;
	long long minn=100000000000;
	for(long long i=0;i<=sx[x];i++){
		if(px[i]==0){
			px[i]=1;
			for(long long j=0;j<=xk[ss[x][i][0]];j++){
				if(ps[xa[ss[x][i][0]][j][0]]==0){
					long long st=t+ss[x][i][1];
					ps[xa[ss[x][i][0]][j][0]]=1;
					minn=min(minn,dfs(st+xa[ss[x][i][0]][j][1]+ss[x][i][1],xa[ss[x][i][0]][j][0],y));
					ps[xa[ss[x][i][0]][j][0]]=0;
				}
			}
			px[i]=0;
		}	
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
//	for(long long i=0;i<n;i++){
//		cin>>x[i].k;
//		for(long long j=0;j<x[i].k;j++){
//			cin>>x[i].a[j][0]>>x[i].a[j][1];
//			s[x[i].a[j][0]].s[x]=i;
//			x++;
//		}
//	}
	for(long long i=0;i<n;i++){
		cin>>xk[i];
		for(long long j=0;j<xk[i];j++){
			cin>>xa[i][j][0]>>xa[i][j][1];
			ss[xa[i][j][0]][sx[xa[i][j][0]]][0]=i;
			ss[xa[i][j][0]][sx[xa[i][j][0]]][1]=xa[i][j][1];
			sx[xa[i][j][0]]++;
		}
	}
	for(long long i=0;i<q;i++){
		long long x,y;
		cin>>x>>y;
		ps[x]=1;
		long long t=w[x]+w[y]+dfs(0,x,y);
		ps[x]=0;
		cout<<t<<endl;
	}
	return 0;
}







