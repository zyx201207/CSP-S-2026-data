#include<bits/stdc++.h>
#define INF (INT_MAX)
using namespace std;

int c, n, m, d, q;
vector<int> w; //µØÌúÕ¾Õ¾¿Úµ½Õ¾Ìü
vector<vector<int>> state;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//code area
	cin>>c>>n>>m>>d>>q;
	w.resize(m);
	for(int i=0;i<m;i++) cin>>w[i];
	state.resize(m);
	for(int i=0;i<m;i++) state[i].resize(m);
	
	for(int i=0;i<n;i++) {
		int k=0;
		cin>>k;
		vector<int> t(m,0);
		vector<int> sthelp(k,-1);
		for(int j=0;j<k;j++){
			int st=0,ti=0;
			cin>>st>>ti;
			sthelp[j] = st-1;
			t[st-1] = ti;
		}
		for(auto from:sthelp){
			for(auto to:sthelp){
				if(from==to) continue;
				state[from][to] = min(state[from][to],t[from]+t[to]);
				if(state[from][to]==0) state[from][to] = t[from]+t[to];
			}
		}
	}
	
	for(int helper=0;helper<m;helper++){ //O(N^2)
		for(int from=0;from<m;from++){
			if(state[helper][from]==0) continue;
			for(int to=from;to<m;to++){
				if(state[helper][to]==0) continue;
				if(from==to) continue;
				state[to][from] = state[from][to] = min(state[from][to],state[from][helper]+state[helper][to]);
				if(state[from][to]==0) state[to][from] = state[from][to] = state[from][helper]+state[helper][to];
			}
		}
	}
	for(int i=0;i<q;i++){
		int from,to;
		cin>>from>>to;
		from--;
		to--;
		cout<<state[from][to]+w[from]+w[to]<<'\n';
	}
	
	return 0;
}

