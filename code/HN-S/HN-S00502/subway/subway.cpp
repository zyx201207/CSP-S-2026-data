#include<bits/stdc++.h>
using namespace std;
struct node{
	int i,j;
}o[1];


short c,n,d;
int q,x,y;
long long m,w[1111],k[1111],inf=0x3f3f,cao[500005],z,a[5005][5005],ans;
vector<int> t[500005];

int dfs(int x,int y,long long l){
if(x==y){
	ans=min(ans,l);
	return 0;
}
for(int i=1;i<=k[x];i++){
	if(a[x][i]==1){
		dfs(i,y,t[x][i]+t[i][x]);
	}
}
return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long aa,tt;cin>>cao[i]>>tt;
			t[i].push_back(tt);
		}
		for(int j=1;j<=k[i];j++){
			for(int kk=1;kk<=k[i];kk++){
				a[cao[j]][cao[kk]]=1;
			}
			a[cao[j]][cao[j]]=0;
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		ans+=inf;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<endl;
	}
	
	

	return 0;
}
