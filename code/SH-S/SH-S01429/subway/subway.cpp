#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k,i1,i2,t1,t2,ans;
bool flg;
int w[500002];//from ground to station
//1-500: line
//501-500500:station
vector<vector<pair<int,int> > > matrix(500502);//ter,len
bool stat[500502];
int mdaaa[500502];

void DFS(int node, int trd){//node,travelled
	//cout << node << " " << trd << endl;
	mdaaa[node] = min(mdaaa[node],trd);
	if (node == t2){
		ans = min(ans,trd);
		//cout << "arriving" << trd << endl;
		return;
	}
	stat[node] = true;
	for (pair<int,int> pp : matrix[node]){
		//cout << node << " " << pp.first << " " << trd+pp.second << " " << mdaaa[node] << endl;
		if (!stat[pp.first] || (trd+pp.second < mdaaa[pp.first])){
			DFS(pp.first, trd+pp.second);
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)cin >> w[i];
	for (int i=1;i<=n;i++){
		cin >> k;
		for (int p=1;p<=k;p++){
			cin >> i1 >> i2;//station, time
			matrix[i].push_back({i1+500,i2});
			matrix[i1+500].push_back({i,i2});
		}
	}
	while (q--){
		cin >> t1 >> t2;
		t1+=500;t2+=500;
		memset(stat,0,m+501);
		for (int o=1;o<=m+500;o++)mdaaa[o]=INT_MAX;
		ans = INT_MAX;
		DFS(t1,0);
		ans += w[t1-500]+w[t2-500];
		cout << ans << "\n";
	}
	return 0;
}
 
