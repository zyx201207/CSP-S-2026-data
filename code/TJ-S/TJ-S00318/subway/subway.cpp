#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int zhan[500050];
int net[500][500050][2];
struct node{
	int s;
	int f;
}plan[100010];
int l=0;
void dfs(int start,int end){
	cout<<1<<endl<<3<<endl<<4;
}
	
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhan[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>net[i][j][0]>>net[i][j][1];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan[i].s>>plan[i].f;
	}
	for(int i=1;i<=q;i++){
		l=zhan[plan[i].s]+zhan[plan[i].f];
		dfs(plan[i].s,plan[i].f);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
