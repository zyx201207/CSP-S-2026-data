#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
const int maxm=490001;
int line[maxn][maxn];
vector<int> station[maxm];
int c,n,m,d,q;
int w[maxm];
int k[maxn],a[maxn][maxm],t[maxn][maxm];
const long long INF=0x3f3f3f;
void init(){
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			line[i][j]=INF;
			if(i==j) line[i][j]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	//输入部分(不含询问) 
	cin>>c>>n>>m>>d>>q;
	//cout<<"OK"<<endl;
	for(int i=1;i<=m;i++) cin>>w[i];
	//cout<<"OK"<<endl;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<t[i][a[i][j]]<<endl;
			station[a[i][j]].push_back(i);
		}
	}
	//cout<<"OK"<<endl;
	//处理出线路间距离 
	for(int i=1;i<=m;i++){
		if(station[i].size()<=1) continue;
		for(auto it1:station[i]){
			for(auto it2:station[i]){
				if(it1==it2) continue;
				cout<<i<<" "<<it1<<" "<<it2<<" "<<t[it1][i]+t[it2][i]<<endl;
				line[it1][it2]=min(line[it1][it2],t[it1][i]+t[it2][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<line[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<t[1][2]<<endl; 
	//询问 
	/*while(q--){
		int x,y;
		cin>>x>>y;
	}*/
}
