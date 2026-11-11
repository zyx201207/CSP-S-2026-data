#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,x,y;
int w[1000],s[1000][1000];
void dfs(int step,int t){
	if(step>y){
		ans=min(ans,t);
		return ;
	}
	for(int i=1;i<n;i++){
		if(s[step][i]!=0){
		return ;
		}
	}	
}
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,b;
		cin>>a>>b;
		s[a][b]=i;
		for(int j=1;j<k;j++){
			cin>>a;
			s[b][a]=i;
			cin>>b;
		}
		s[a][b]=i;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
