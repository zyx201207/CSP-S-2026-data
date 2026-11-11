#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、铁站数、每个地铁站最多被几条线路经过，出行计划数
int w[500000];//每个地铁站的地铁口走到站厅需要的时间
int k[501],a[501][21],t[501][21],rx,ry,dtz[500000][501],st[500000],df[500000],kf[500000];
int dfs(int n,int time,int zt){
	int ans=-1;
	if(zt==1){
		if(n==ry){
		return time;
		
}

	for(int i=1;i<=st[n];i++){
		if(kf[dtz[n][i]]==1){
			continue;
		}else{
		kf[dtz[n][i]]=1;
		
			int aa=dfs(dtz[n][i],time+a[dtz[n][i]][n],2);
		kf[dtz[n][i]]=0;
			if(aa==-1){
				continue;
			}	
			if(ans==-1)ans=aa;
			ans=min(ans,aa); 
			}
		}
		
		
		
	}else{

		for(int i=1;i<=k[n];i++){
			if(df[a[n][i]]==1){
				continue; 
			}else {
				df[a[n][i]]=1;
			int aa=dfs(a[n][i],time+t[n][a[n][i]],1);
			df[a[n][i]]=0;
			if(aa==-1){
				continue;
			}
				if(ans==-1)ans=aa;
			ans=min(ans,aa);
			}
		}
	}
return ans  ;

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
		cin>>	a[i][j]>>t[i][j];//第i地铁遇到第a[i][j]个地铁站 
		st[a[i][j]]++;
		
		dtz[a[i][j]][st[a[i][j]]]=j;
		
		}
	}
    
	for(int kk=1;kk<=q;kk++){
		memset(df,0,sizeof(df));
			memset(kf,0,sizeof(kf));
	int ans;
	cin>>rx>>ry;
	df[rx]=1;
	int cc=dfs(rx,w[rx]+w[ry],1);
		
		
		cout<<cc<<endl;
		
		
	}
	return 0;
} 
