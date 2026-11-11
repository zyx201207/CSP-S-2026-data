#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int > v[N];
int c;//测试点编号、地铁线路数、地铁站数
int n,m,d,q,w[N],s[N],a[N],t[N];//每个地铁站最多被几条线路经过，以及出行计划数
int mp[N][N],mp1[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[i].push_back(a[i][j]);
			mp[i][a[i][j]]=i;
			mp1[i][a[i][j]]=j;
		}
	}
	while(q--){
		cin>>x>>y;
		int cnt=0,flag=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s[i];j++){
				if(mp[i][a[i][j]]==i){
					cnt+=w[g]+t[i][mp1[i][a[i][j]]];
					for(auto g:v[i]){
						for(int k=1;k<=n;k++){
							if(mp[k][g]==k){
								i=mp[i][g];
							}
						}
						
					}
				}
			}
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
