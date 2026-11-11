#include <bits\stdc++.h>
using namespace std;

struct station{
	int id;
	vector(int)
};

int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	int c,n,m,d,q;
	fin >> c >> n >> m >> d >> q;
	vector<int> t1(m+10,INT_MAX);
	map<pair<int,int>,int> array;
	map<int,vector<int> > stations;
	map<pair<int,int>,int> transfer;
	for(int i=1;i<=m;i++) fin >> t1[i];
	for(int i=0;i<n;i++){
		int jm;
		fin >> jm;
		vector<int> costs(m+10,-1);
		for(int j=0;j<jm;j++){
			int id,cost;
			fin >> id >> cost;
			costs[id] = cost;
			for(int l=0;l<stations[id].size();l++) transfer[{l,i}] = 2*cost;
			stations[id].push_back(i);
		}
		for(int j=1;j<=m;j++){
			if(costs[j]==-1) continue;
			for(int k=j+1;k<=m;k++){
				if(costs[k]==-1) continue;
				int jkc = costs[j]+costs[k]+t1[j]+t1[k];
				if(array[{j,k}]==0) array[{j,k}]=jkc;
				array[{j,k}]=min(jkc,array[{j,k}]);
			}
		}
	}

	for(int i=0;i<q;i++){
		int s,e;
		fin >> s >> e;
		if(s==e) fout << 0 << '\n';
		else fout << array[{s,e}] << '\n';
	}
	return 0;
} 
