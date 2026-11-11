//西安铁一中滨河高级中学 耿禹墨 SN-S00334
#include<bits/stdc++.h>
using namespace std;
struct rq{
	int x,y;
}r[100005];
int c,n,m,d,q;
int w[500005],k[505],a[25][505],t[25][505],faa[25][505];
inline bool find(int x,int y,int z){
	if(faa[x][y]!=z) return false;
	else return true;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			faa[i][j]=t[i][j];
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			if(a[i][j]==a[i+1][j])
				faa[i][j]=t[i+1][j];
		}
		
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		for(int j=r[i].x;j<=r[i].y;j++){
			sum+=w[r[i].x]+w[r[i].y];
			for(int s=1;s<n;s++){
				for(int l=1;l<k[s];l++){
					if(!find(s,l,t[s][l])){
						sum+=t[s][l-1]+t[s+1][l-1];
					}
				}
			}
		}
		cout<<sum<<'\n'; 
	}
	return 0;
}
