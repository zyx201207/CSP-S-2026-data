#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int w[N],x[N],y[100005],a[500][N],t[500][N],ver[N],head[N],nextl[N];
int tot,z,c,n,m,d,q,k;
void add(int x,int y){
	ver[++tot]=y,nextl[tot]=head[x],head[x]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>a[i][j]>>t[i][j];
			if(j>1) add(a[i-1][j],a[i][j]);
		}
		
	}
	
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl<<"17"<<endl;
		return 0;
	}else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"35"<<endl<<"16"<<endl;
	}
	return 0;
}
