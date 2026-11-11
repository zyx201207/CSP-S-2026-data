 #include<bits/stdc++.h>
 #define QwQ 0
 using namespace std;
 const int N=2e6+10;
 vector<int>g[N];
 int main(){
 	freopen("hub.in","r",stdin);
 	freopen("hub.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		//zhe dao ti wo zhen bu hui, jin tian jiu dao zhe li ba.
		//yi lian xu zuo ti 3.5h, yao zhu yi xiu xi ou!
		//zhe ci bi sai si hu bi CSP-S 2025 jian dan,mu qian wo yin gai zai 3~2 zhi jian,
		//jin nian bi sai bao ming hua le wo 600 duo ,* i y kou nzn de ymeC*ue lheag luee. 
	}
 	return QwQ;
 }

