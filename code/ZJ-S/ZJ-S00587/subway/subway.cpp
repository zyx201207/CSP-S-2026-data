#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[501],k[501],a[501][501],t[501][501];
bool b[501],bl[501];
int dfs(int id,int end,int time,int line){
	int ans=100;
	if(id==end) return time;
	if(line==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==id&&bl[i]==0){
					bl[i]=1;
					ans=min(ans,dfs(id,end,time+t[i][j],i));
				}
			}
		}
	}
	else{
		for(int i=1;i<=k[line];i++){
			if(b[a[line][i]]==0){
				b[a[line][i]]=1;
				ans=min(ans,dfs(a[line][i],end,time,line));
				b[a[line][i]]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==id&&i!=line&&bl[i]==0){
					bl[i]=1;
					ans=min(ans,dfs(id,end,time+t[i][j],0));
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		b[x]=1;
		cout<<dfs(x,y,0,0)+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
