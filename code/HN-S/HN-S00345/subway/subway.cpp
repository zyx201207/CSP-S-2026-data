#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+5;
int bianhao;
int n,m,d,q;
int w[N];
int k[505];
int v[505][N];
int edge[N][N];
vector<vector<int> > t(505);
int tw; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(edge,0x3f,sizeof edge);
	cin>>bianhao>>n>>m>>d>>q;
	for(int i =1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>tw;
			t[i].push_back(tw);
			cin>>v[i][tw];
		}
		for(int j=0;j<t[i].size();j++){
			for(int g=j+1;g<t[i].size();g++){
				int j1=t[i][j],g1=t[i][g];
				edge[j1][g1]=min(edge[j1][g1],v[i][j1]+v[i][g1]);
				edge[g1][j1]=edge[j1][g1];
			}
		}
	}
//	cout<<edge[1][2]<<" "<<edge[2][3]; 
	for(int i =1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int g=1;g<=m;g++){
				edge[i][j]=min(edge[i][j],edge[i][g]+edge[g][j]);
				//cout<<i<<" "<<g<<" "<<j<<" "<<edge[1][2]<<endl; 
			}
		}
	}
	int st,en;
	while(q--){
		cin>>st>>en;
		cout<<edge[st][en]+w[st]+w[en]<<endl; 
	}
	return 0;
}
