#include<bits/stdc++.h>
using namespace std;
int ans;
bool v[500001];
int c,n,m,d,q;
int w[500001];
vector <int> a[500001];
vector <int> b[500001];
void dfs(int start1,int to1,int step){
	cout<<start1<<endl;
	v[start1]=1;
	if(start1==to1){
		ans=min(ans,step);
		return ;
	}
	for(int i=1;i<=n;i++){
		int k=a[i].size();
		for(int j=1;j<=k;j++){
			if(a[i][j]==start1&&v[a[i][j+1]]==0){
				dfs(a[i][j+1],to1,step+b[i][j+1]);
			}
			if(a[i][j]==start1&&v[a[i][j-1]]==0){
				dfs(a[i][j-1],to1,step+b[i][j-1]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,k;
			cin>>y>>k;
			a[i].push_back(y);
			b[i].push_back(k);
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		for(int i=1;i<=m;i++)
		v[i]=0;
		ans=99999;
		dfs(xr,yr,0);
		cout<<ans<<endl;
	}
	return 0;
}
