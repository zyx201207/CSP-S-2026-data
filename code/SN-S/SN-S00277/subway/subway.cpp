#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,x,y,ans;
int w[500100];
struct tree{
	int k,id;
	int a[1010],t[1010];
	int dy[1010];
};
int lu[510][510];
tree q[510];
vector<int>s[510];
bool vis[500100];
void dfs(int o,int sum,int z){
    //cout<<o<<" "<<sum<<"   ";
	if(o==y){
	//	cout<<'\n';
		int summ=sum+q[z].t[q[z].dy[o]];
		//cout<<q[z].t[q[z].dy[o]]<<'\n';
		ans=min(ans,summ);
		return;
	}
	//cout<<o<<" "<<sum<<" "<<s[o].size()<<'\n';
	//for(int i=0;i<s[o].size();i++)cout<<s[o][i]<<" ";
	//cout<<'\n';
	for(int i=0;i<s[o].size();i++){
		if(vis[s[o][i]]==0){
			vis[o]=1;
			//cout<<o<<"->";
				if(lu[o][s[o][i]]!=z){
					dfs(s[o][i],sum+q[lu[o][s[o][i]]].t[q[lu[o][s[o][i]]].dy[o]]+q[z].t[q[z].dy[o]],lu[o][s[o][i]]);
				}else{
					dfs(s[o][i],sum,lu[o][s[o][i]]);
				}
			vis[o]=0;
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>q[i].k;
		for(int k=1;k<=q[i].k;k++)cin>>q[i].a[k]>>q[i].t[k];
		for(int k=1;k<q[i].k;k++){
			s[q[i].a[k]].push_back(q[i].a[k+1]);
			s[q[i].a[k+1]].push_back(q[i].a[k]);
			lu[q[i].a[k]][q[i].a[k+1]]=i;
			lu[q[i].a[k+1]][q[i].a[k]]=i;
		}
		for(int k=1;k<=q[i].k;k++){
			q[i].dy[q[i].a[k]]=k;
			q[i].id=i;
		}
	}
	/*
	for(int i=1;i<=m;i++)cout<<lu[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			cout<<i<<"->"<<s[i][j]<<'\n';
		}
	}
	*/
	while(Q--){
		ans=0xfffffff;
		cin>>x>>y;
		if(x==y)cout<<0<<'\n';
		else{
			for(int i=0;i<s[x].size();i++){
				
				vis[x]=1;
				//cout<<x<<"->";
				dfs(s[x][i],w[x]+w[y]+q[lu[x][s[x][i]]].t[q[lu[x][s[x][i]]].dy[x]],lu[x][s[x][i]]);
			    vis[x]=0;
			}	
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

I will become better! 
*/

