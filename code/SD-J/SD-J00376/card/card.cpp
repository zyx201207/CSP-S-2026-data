#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	//vector<vector<bool>> dp(m, vector<bool> (m))
	vector<int> cnt(m);
	vector<int> ans(m);
	vector<int> ctl(m,1);
	set<int> st;
	for (auto &i : v){
		cin>>i;
		cnt[i-1]++;
	}
	for (int i=n-1;i>=0;i--){
		if (st.find(v[i])==st.end()){	
			st.insert(v[i]);
			//ans[v[i]-1]+=1;
			for (auto it = st.begin();it!=st.end();++it) if(ctl[*it-1]) ans[*it-1]+=cnt[v[i]-1];
			//cerr<<"i:"<<i<<"; "<<"v[i]: "<<v[i]<<" -> ";
			//for (auto i1 : ans) cerr<<i1<<" ";
			//cerr<<"|| ";
			//for (auto i1 : ctl) cerr<<i1<<" ";
			//cerr<<endl;
		}
		else{ 
			if(ctl[v[i]-1]){
				for (auto it = st.begin();it!=st.end();++it) ctl[*it-1] = 0;
				ctl[v[i]-1] = 1;
			}
		}
		if (st.size()==n) break;
	}
	for (auto i : ans) cout<<i<<" ";
	cout<<endl;
}
