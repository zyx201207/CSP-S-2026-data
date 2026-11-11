#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],ans=INT_MAX,en;
bool point[110000][510];
vector<int> sub[N],way[N];
map<pair<int,int>,int> mp;

void dfs(int line,int f,int aans){
//	cout<<"line="<<line<<" f="<<f<<" aans="<<aans<<"\n";
	int ls=sub[f].size();
	for(int i=0;i<=ls-1;i++) {
		int lw=way[sub[f][i]].size();
		for(int j=0;j<=lw-1;j++){
			if(sub[f][i]==line) {
				if(way[line][j]==en){
					ans=min(ans,aans+mp[make_pair(line,en)]+a[en]);
					return ;
				}
				if(point[line][way[line][j]]==0 && sub[way[line][j]].size()>=1){
					point[line][way[line][j]]=1;
					dfs(line,way[line][j],aans);
				}
			}
			else if(sub[f][i]!=line) {
//				if(way[sub[f][i]][j]==en){
//					ans=min(ans,aans+mp[make_pair(line,way[sub[f][i]][j])]+mp[make_pair(sub[f][i],way[sub[f][i]][j])]+mp[make_pair(sub[f][i],en)]+a[en]);
//					return ;
//				}
				if(point[sub[f][i]][way[line][j]]==0){
					point[sub[f][i]][way[line][j]]=1;
					dfs(sub[f][i],way[sub[f][i]][j],aans+mp[make_pair(line,way[sub[f][i]][j])]+mp[make_pair(sub[f][i],way[sub[f][i]][j])]);
				}
			}
		}
		
	}
	point[line][f]=0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++) {
			int sta,val;
			cin>>sta>>val;
			sub[sta].push_back(i);
			way[i].push_back(sta);
			mp[make_pair(i,sta)]=val;  
		}
	}
	for(int i=1;i<=q;i++){
		ans=INT_MAX;
		int st;
		cin>>st>>en;
		int ls=sub[st].size();
		for(int i=0;i<=ls-1;i++) dfs(sub[st][i],st,a[st]+mp[make_pair(sub[st][i],st)]); 
		cout<<ans<<"\n";
	}
	
	return 0;
}
