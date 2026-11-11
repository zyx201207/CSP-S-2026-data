#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int t[1005][1005];
bool b[1005][1005];
int e[1005][1005];
int w[1300];
int c,n,m,d,q;
int k;
int x,y,sum=0;
void dfs(int x,int y,int k){
	if(x==y){
		sum=min(sum,k);
		return;
	}
	for(int i=1;i<=m;i++){
		if(b[x][i]==true){
			b[x][i]=false;
			k+=t[x][i];
			dfs(i,y,k);
			b[x][i]=true;
			k-=t[x][i];
		}	
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
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			b[i][j]=true;
			b[j][i]=true;		
		}
	}
	while(q--){
		sum=0;
		cin>>x>>y;
		sum=sum+w[x]+w[y];
		dfs(x,y,sum);
		cout<<sum<<endl;
	} 
	return 0;
} 
