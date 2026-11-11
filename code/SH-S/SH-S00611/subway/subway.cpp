#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<int> sta[500];
vector<int> hc[500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int o,tmp;
			cin>>o>>tmp;
			sta[i].push_back(o);
			hc[i].push_back(tmp);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int tmp1,tmp2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sta[i].size();j++){
				if(sta[i][j]==x){
					tmp1=i;
					i=n+1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sta[i].size();j++){
				if(sta[i][j]==y){
					tmp2=i;
					i=n+1;
					break;
				}
			}
		}
		if(tmp1==tmp2)
			cout<<w[x]+w[y]+hc[tmp1][x]+hc[tmp1][y]<<endl;
		else{
			int a=tmp2-tmp1+1;
			int ans=a*hc[1][1];
			cout<<ans+w[x]+w[y]<<endl;
		}
		cout<<hc[tmp1][x];
	}
	return 0;
}
