#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn=5005;
ll c,t; 
ll n,d;
ll y[maxn];
ll cnt[maxn][maxn];
ll ans;
vector<ll> v[maxn];

void bfs(ll root){
	memset(cnt,sizeof(cnt),0);
	ll dep=0;
	queue<ll> q1,q2;
	q1.push(root);
	while(!q1.empty()||!q2.empty()){
		while(!q1.empty()){
			ll r=q1.front();
			cnt[dep][r]++;
			q1.pop();
			for(int i=0;i<v[r].size();i++){
				q2.push(v[r][i]);
			}
		}
		dep++;
		while(!q2.empty()){
			ll r=q2.front();
			cnt[dep][r]++;
			q2.pop();
			for(int i=0;i<v[r].size();i++){
				q1.push(v[r][i]);
			}
		}
		dep++;
	}
	for(int i=1;i<dep;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2)    ans++;
//			cout<<cnt[i][j]<<' ';
		}
//		cout<<endl;
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>y[i];
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(y[j]-y[i]>d)    break;
				v[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<' ';
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
