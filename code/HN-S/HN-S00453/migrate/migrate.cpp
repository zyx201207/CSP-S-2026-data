#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1;
const int M=1e5+1;
int mi[M][M];
long long a[N],ans;
int c,t;
int n;
long long d;
int cnt[M][M];

void minroad(int x,int y,int step){
	
	if(x==y){
		mi[x][y]=min(mi[x][y],step);
		return;
	}
	
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) minroad(j,y,++step);
			else return;
		}
	}
	
}

void dfs(int x,int y,int step){
	if(x==y && step==mi[x][y]){
		cnt[x][y]++;
		return;
	}
	if(cnt[x][y]>=3) return;
	
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) dfs(j,y,++step);
			else return;
		}
	}
}

int main(){
	
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		
		for(int j=1;j<=n;j++)
		    for(int k=j+1;k<=n;k++) mi[j][k]=0x3f3f3f3f;
		
		for(int j=1;j<=n;j++) cin>>a[i];
		
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++) minroad(j,k,0);
			
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++) dfs(j,k,0);
			
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++) if(cnt[j][k]==2) ans++;
		
		cout<<ans<<endl;
			
			
		
	}
	
	return 0;
}
