#include<bits/stdc++.h>
using namespace std;
//(TLE 40)
void change(vector<vector<int> > &cost, int i, int j,int m){
	if(i==j) return;
	for(int k=0;k<m;k++){
		if(cost[j][k] >= 1e9) continue;
		cost[i][k] = cost[k][i] = min(cost[i][k], cost[i][j]+cost[j][k]);
		change(cost, i, k, m);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	vector<int> io(m);
	for(int i=0;i<m;i++) cin>>io[i];
	
	vector<vector<int> > cost(m,vector<int>(m,1e9));
	for(int i=0;i<m;i++) cost[i][i] = 0;
	for(int i=0;i<n;i++){
		int k; cin>>k;
		vector<pair<int,int> > tmp(k);
		for(int j=0;j<k;j++){
			int t1,t2;
			cin>>t1>>t2;
			tmp[j].first = t1-1;
			tmp[j].second = t2;
		}
		
		
		for(int j=0;j<k;j++){
			int A = tmp[j].first;
			int sp = tmp[j].second;
			for(int jj=j+1;jj<k;jj++){
				int B = tmp[jj].first;
				sp+=tmp[jj].second;
				cost[A][B] = sp; cost[B][A] = sp;
				
				sp-=tmp[jj].second;
			}
		}
		
	}
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(cost[i][j] < 1e9) change(cost,i,j,m);
		}
	}
	*/
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(cost[i][j] < 1e9){
				for(int k=0;k<m;k++){
					if((cost[j][k] >= 1e9) || k==i || k==j) continue;
					cost[i][k] = cost[k][i] = min(cost[i][k], cost[i][j]+cost[j][k]);
				}
			}
		}
	}
	
	for(int i=0;i<q;i++) {
		int t1,t2;
		cin>>t1>>t2;
		cout<<(io[t1] + cost[t1][t2] + io[t2])<<'\n';
	}
	
	
	return 0;
}
