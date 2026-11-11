#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[11];
struct s{
	int sum;
	int num;
};
int a[4][11][11];
int t[4][11];
int ans;
int dfs(int f,int e){
	
}
int visit[11];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)visit[i]=0;
	int a1[11];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a1[j]>>t[i][j];
		}
		int a2=a1[1];
		for(int j=2;j<=x;j++){
			a[a2][a1[j]]=1;
			a[a1[j]][a2]=1;
			a2=a1[j];
		}
	}
	int f,e;
	for(int i=1;i<=q;i++){
		cin>>f>>e;
		int num=
		dfs(f,e);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
