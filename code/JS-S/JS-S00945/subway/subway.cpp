#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,p,a[500005],b[500005][505],s[100005],e[100005],ans,xian[505][505],js;
int d1[4]={0,1,0,-1};
int d2[4]={1,0,-1,0};
int mama[505][505];
void bfs(int x,int y,int cnt,int jy){
	if(x==y){
		ans=min(ans,cnt);
		return;
	}
	if(jy==0){
		js++;
		bfs(x,y,cnt,xian[x][js]);
		return;
	}
	js=0;
	for(int i=1;i<=m;i++){
		if(mama[x][i]==1){
			
			bfs(i,y,cnt+=b[x][i]+b[x][jy],jy);
			
		}
	}
}



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	
	
	
	
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int li[k];
		for(int j=1;j<=k;j++){
			int ss;
			
			cin>>ss;
			li[j]=ss;
			cin>>b[ss][i];
			xian[ss][k]=1;
		}
		for(int j=1;j<=k;j++){
			for(int ij=1;ij<=k;ij++)mama[li[j]][li[ij]]=1;
			
		}
		
		
	}
	for(int i=1;i<=p;i++){
		cin>>s[i]>>e[i];
	}
	
	
	for(int i=1;i<=p;i++){
		bfs(s[i],e[i],a[s[i]]+a[e[i]],xian[e[i]][1]);
		cout<<ans<<endl;
		ans=0;
	}
		
	
	
	
	
	
	return 0;
}
