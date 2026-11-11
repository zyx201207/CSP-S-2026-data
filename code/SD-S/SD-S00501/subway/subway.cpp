#include<bits/stdc++.h>
using namespace std;
long long w[500010],ans[500510],f[500010][32],dep[500010];
struct node{
	int to;
	long long xh;
};
vector <node> vc[500510];
void spfa(int h){
	queue <int> q;
	q.push(h);
	ans[h]=0;
	f[h][0]=h;
	dep[h]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<vc[x].size();i++){
			if(ans[vc[x][i].to]>vc[x][i].xh+ans[x]){
				ans[vc[x][i].to]=vc[x][i].xh+ans[x];
				f[vc[x][i].to][0]=x;
				dep[vc[x][i].to]=dep[x]+1;
				q.push(vc[x][i].to);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m+n;i++) ans[i]=1e18;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int v,u;
			cin>>v>>u;
			vc[v].push_back({m+i,u});
			vc[m+i].push_back({v,u});
		}
	}
	spfa(1);
//	cout<<f[3][0]<<" ";
	for(int i=1;i<=30;i++){
		for(int j=1;j<=m+n;j++){
			//cout<<f[f[j][i-1]][i-1];
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	//cout<<f[3][0]<<" ";
	//cout<<ans[7]<<" ";
	//cout<<ans[31]<<" "<<ans[32];
	//cout<<ans[f[32][0]]<<" ";
	//return 0;
	while(q--){
		int l,r;
		cin>>l>>r;
		//cout<<ans[r]<<" ";
		if(l==1||r==1){
			cout<<max(ans[r],ans[l])+w[l]+w[r]<<"\n";
		}else{
			//cout<<1<<" ";
			long long ans1=ans[l]+ans[r]+w[l]+w[r];
			if(dep[l]<dep[r]) swap(l,r);
			if(dep[l]!=dep[r]){
				for(int i=30;i>=0;i--){
					if(dep[f[l][i]]>dep[r]){
						l=f[l][i]; 
					}
				}
				//if(l==31||r==31))
				l=f[l][0];
			}
			//cout<<l<<" ";
			if(l==r){
				ans1-=ans[l]*2;
			}else{
				for(int i=30;i>=0;i--) if(f[l][i]!=f[r][i]) l=f[l][i],r=f[r][i]; 
				l=f[l][0];
				ans1-=ans[l]*2;
			}	
			cout<<ans1<<"\n";
		}
	}
	return 0;
}
