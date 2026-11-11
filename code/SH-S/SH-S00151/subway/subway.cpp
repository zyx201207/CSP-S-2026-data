#include<bits/stdc++.h>
using namespace std;
const int Nww=2*1e4+9;
const int Nmm=5*1e5+9;
const int Nqq=1e5+9;
int c,n,m,d,q;
int w[Nww];
int ans;
int liantong[1009][1009],v[1009][1009];
bool vis[1009][1009];
void dfs(int s,int f,int line,int c){
//	cout<<s<<","<<line<<","<<c<<endl; 
	if(vis[s][line])return;
	vis[s][line]=1;
	if(s==f){
		ans=min(ans,c+v[f][line]+w[f]);
		return ;
	} 
	
	if(liantong[s][line]==0)return;
	dfs(liantong[s][line],f,line,c);

	for(int i=1;i<=n;i++){
		if(i==line)continue;
		if(v[s][i])dfs(s,f,i,c+v[s][line]+v[s][i]);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,from,x,y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			if(j==1)from=x;
			else{
				liantong[from][i]=x;
				from=x;
			}
			v[from][i]=y;
		}
	}
//	for(int i=1;i<=5;i++){for(int j=1;j<=5;j++){cout<<liantong[i][j]<<" ";}cout<<endl;}
//	for(int i=1;i<=5;i++){for(int j=1;j<=5;j++){cout<<v[i][j]<<" ";}cout<<endl;}
		for(int i=1;i<=q;i++){

		
		int s,f;
		cin>>s>>f;
		ans=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(v[s][j]){
//				cout<<"rec"<<s<<","<<j<<","<<v[s][j]<<endl;
						memset(vis,0,sizeof(vis));
				dfs(s,f,j,v[s][j]+w[s]);
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
