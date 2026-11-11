#include<bits/stdc++.h>
using namespace std;
int z,n,m,d,t,ans;
struct station{
	int id,w;
	int c[105][105];
	bool vis;
}s[5005];
struct line{
	int as,id;
	int sta[5005];
}l[5005];
void dfs(int x,int y,int cnt,int ln){
	if(x==y){
		ans=min(ans,cnt);
		return;
	}
	s[x].vis=true;
	for(int i=1;i<=m;i++){
		if(s[x].c[i][ln]!=0){
			dfs(l[i].sta[x+1],y,cnt+s[x].c[i][ln],i);
			dfs(l[i].sta[x-1],y,cnt+s[x].c[i][ln],i);
		}
	} 
	s[x].vis=false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>z>>n>>m>>d>>t;
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
		s[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>l[i].as;
		l[i].id=i;
		for(int j=1;j<=l[i].as;j++){
			cin>>l[i].sta[j];
			cin>>s[l[i].sta[j]].c[i][0];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++){
			for(int k=1;k<=d;k++){
				if(s[i].c[j][0]!=0&&s[i].c[k][0]!=0)    s[i].c[j][k]=s[i].c[j][0]+s[i].c[k][0];
			}
		}
	}
	while(t--){
		int x,y;
		cin>>x>>y;
		ans=0;
		for(int i=1;i<=n;i++)    s[i].vis=false;
		dfs(x,y,0,0);
	}
	return 0;
} 













