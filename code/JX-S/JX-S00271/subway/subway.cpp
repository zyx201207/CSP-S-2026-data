#include<bits/stdc++.h>

#define repeat(s) for(int i=0;i<s;++i);

using namespace std;

typedef long long ll;

struct node{
	int x; // a: ID of subway station
	int t; // a: distance of bar to lobby
};

int c,n,m,d,q,in,ink,ina,x,y;

unsigned int res=-1;

vector<int> w;
vector<vector<node>> a;

vector<vector<int>> con;

bitset<500005> vis;

vector<ll> dp;


void dfs(int b,ll sum,int st){

	// b is lobby ID

	if(sum<dp[b]){
		dp[b]=sum;
	}else{
		return;
	}

	if(b==y)return;


	vis[b]=true;

	for(auto &p:con[b]){      // p : ID of way

		if(p!=st)

			for(auto &k:a[p]){    // k : lobby of goal in way

				if(!vis[k.x]){

					int i;
					for(i=0;a[p][i].x!=b;i++);

					dfs(k.x,
						sum +a[p][i].t +k.t,
						p
					);
				}

			}
	}

	

	return;
}



int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;

	dp.resize(m+1);
	con.resize(m+1);

	for(int i=0;i<m;i++){
		cin>>in;

		w.push_back(in);
	}

	

	for(int i=0;i<n;i++){

		// i of ways

		cin>>ink;

		vector<node> tmp;
		for(int j=0;j<ink;j++){
			cin>>ina>>in; // a & t
			tmp.push_back({ina,in});

			con[ina].push_back(i);

		}
		a.push_back(tmp);

		
	}




	

	while(q--){
		cin>>x>>y;

		//---init---

		fill(dp.begin(),dp.end(),0x7FFFFFFFFFFFFFFF);

		bitset<500005> o;
		vis=o;

		ll ans=w[x-1]+w[y-1];

		//---solve---

		dfs(x,0,-1);

		

		ans+=dp[y];

		cout<<ans<<'\n';
	}

	

	return 0;
}



