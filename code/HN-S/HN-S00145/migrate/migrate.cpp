#include<bits/stdc++.h>
using namespace std;
int c,n,ans,w;
int dist[100][100];
vector<int> a;
void dfs(int s,int f,int step,int q,int z){
	if(step==f){
		if(dist[s][f]>=q){
			dist[s][f]=q;
		}
		return ;
	}
	for(int i=step+1;i<=z;i++){
		if(a[i]-a[step]<=w){
			dfs(s,f,i,q+1,z);
		}
	}
}
void dfs1(int s,int f,int step,int q,int z){
	if(step==f){
		if(dist[s][f]==q){
			ans++;
		}
		return ;
	}
	for(int i=step+1;i<=z;i++){
		if(a[i]-a[step]<=w){
			dfs(s,f,i,q+1,z);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate,out","w",stdout);
	cin>>c>>n;
	//cout<<c<<n;
	while(n--){
		int q;
		//cout<<"1";
		cin>>q>>w;
		memset(dist,0x3f3f3f3f,sizeof(dist));
		a.clear();
		a.resize(q+1);
		for(int i=1;i<=q;i++){
			cin>>a[i];
			//cout<<"7";
		}
		for(int i=1;i<q;i++){
			for(int j=i+3;j<=q;j++){
				dfs(i,j,1,0,q);
			}
		}
		for(int i=1;i<q;i++){
			for(int j=i+3;j<=q;j++){
				dfs1(i,j,1,0,q);
				//cout<<dist[i][j]<<" ";
			}
		}
		if(ans>1){
			cout<<ans-1<<"\n";
		}else{
			cout<<"0"<<"\n";
		}
		//cout<<ans<<"\n";
	}
	return 0;
}
