#include <bits/stdc++.h>
using namespace std;
typedef long long inte;
inte check(inte p,vector<inte> a, inte m){
	inte cnt=0;
	for(int i=1;i<=a.size();i++){
		if(a[i]<p){
			cnt+=p-a[i];
		}
	}
	return cnt;
}
struct Node{
	inte t, l;// time line 
	Node(inte t, inte l):t(t), l(l){
	};
};
struct Cont{
	inte l, wt;// line, walk-time
	Cont(inte l, inte wt):l(l), wt(wt){
	};
};
inte find_n(vector<inte> &v, inte n, bool indexed_1=false){
	for(inte i=0+indexed_1;i<v.size()+indexed_1;i++){
		if(v[i]==n){
			return i;
		}
	}
	return -1;
}
inte find_ct(vector<Cont> &v, inte l, bool indexed_1=false){
	for(inte i=0+indexed_1;i<v.size()+indexed_1;i++){
		if(v[i].l==l){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	ios::sync_with_stdio(false);
	int c, n, m, d, Q;
	cin>>c>>n>>m>>d>>Q;
	vector<inte> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<vector<Cont>> sts(m+1);
	vector<vector<inte>> lns(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			inte aipt, tipt;
			cin>>aipt>>tipt;
			sts[aipt].push_back(Cont(i, tipt));
			lns[i].push_back(aipt);
		}
	}
	for(int _=1;_<=Q;_++){
		//clog<<"############################Q"<<_<<"############################"<<endl;
		inte x, y;
		cin>>x>>y;
		queue<Node> q;
		for(auto &i:sts[x]){
			q.push(Node(w[x]+i.wt, i.l));
		}
		while(!q.empty()){
			auto f = q.front();
			q.pop();
			//clog<<"F.t:"<<f.t<<" F.l:"<<f.l<<endl;
			if(find_n(lns[f.l], y)!=-1){
				//clog<<"Find exit:"<<f.t+(sts[y][find_ct(sts[y], f.l)].wt)+w[y]<<endl;
				cout<<f.t+(sts[y][find_ct(sts[y], f.l)].wt)+w[y]<<endl;
				break;
			}
			for(int i=0;i<lns[f.l].size();i++){ // i means stations
				inte st = lns[f.l][i]; // chose-station
				inte wt1 = sts[st][find_ct(sts[st],f.l)].wt;// walk-out time
				for(int j=0;j<sts[st].size();j++){ // j means connections
					//clog<<"Putting:"<<" Station:"<<st<<" Turning line:"<<sts[st][j].l<<endl;
					q.push(Node(f.t+wt1+sts[st][j].wt, sts[st][j].l));
				}
			}
		}
	}
	return 0;
} 
