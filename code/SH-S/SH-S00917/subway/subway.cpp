#include<bits/stdc++.h>
using namespace std;
const int N=509;
int c,n,m,d,q,w[N];
struct subway{
	int zhan,time;
};
subway sub[29][509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=6&&c>=12){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				w[i]=(x,y);
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]<<endl;
		}
		return 0;
	}
	else{
		for(int i=1;i<=m;i++) cin>>w[i];
		int short_pass[509][509];
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				short_pass[i][j]=1e19;
		for(int i=1;i<=n;i++){
			int k,x1,t1,x2,t2;
			cin>>k;
			cin>>x1>>t1>>x2>>t2;
			short_pass[x1][x2]=min(t1+t2,short_pass[x1][x2]);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+short_pass[x][y]<<endl;
		}
		return 0;
	}
}

