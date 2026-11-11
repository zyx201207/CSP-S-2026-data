#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int x[N],vis[N];
int n,d;
int T=0;

bool check(int s,int t){
	queue<pair<int,int>>q;
	q.push({s,0});

	int ans=0;
	int f=1e9; 
	map<int,int>mp;
	while(q.size()){
		int pos=x[q.front().first],id=q.front().first,dis=q.front().second;
		q.pop();
//		if(vis[id]==T)continue;
		vis[id]=T;
		for(int i=id+1;i<=t;i++){
			if(x[i]>pos+d)break;
			if(i==t){
				f=min(f,dis);
				mp[dis]++;
				if(mp[f]==3)
					return 0;
			}
			if(dis+1<f)
				q.push({i,dis+1});
		}
	} 
	if(mp[f]==2){
		return 1;
	}
	return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11 or c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int T=x[2]-x[1];
			
			if(d<=T){
				cout<<0;
			}
			else if (d>=2*T){
				cout<<(x[n]-x[1])/T-3<<endl;
			}
			else{
				cout<<0;
			}
			cout<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		cerr<<"ok"<<endl;
		int cnt=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
//			cerr<<u<<" "<<v<<endl; 
				if(check(u,v)){
					cnt++;	
				}
			}
		}
		cout<<cnt<<endl;
	} 
    return 0;
}

/*
0 2
5 3 
-2 -1 0 1 2
*/
