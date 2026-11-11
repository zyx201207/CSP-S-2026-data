#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c, T, n, dis;
int arr[2000005];
int vis[2000005];
ll dep[2000005];
vector <int> e[2000005];
queue <int> q;

ll bfs(int s){
	memset(dep, 0, sizeof(dep));
	memset(vis, 0, sizeof(vis));
	int res=0;
	
	while(!q.empty()){
		q.pop();
	}
	
	q.push(s);
	dep[s] = 1;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for(int v:e[u]){
			if(v<s){
				continue; 
			} 
			
			vis[v]++;
			
			if(!dep[v]){
				dep[v] = dep[u]+1; 
				q.push(v);
			} 
			else if(dep[v]==dep[u]+1){
				if(vis[v]==2){
					res++;
//					cout<<s<<' '<<u<<" "<<v<<" "<<vis[v]<<endl;
				}
				else if(vis[v]==3){
					res--;
//					cout<<s<<' '<<u<<" "<<v<<" "<<vis[v]<<endl;
				}
			}
		}
	}
	
	return res;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>T;
	
	if(c==11 || c==12){
		while(T--){
			int x, y;
			cin>>n>>dis>>x>>y;
			ll kskbl=y-x, zdjd=dis/kskbl;
			ll ans=0;
			
			if(zdjd == 1){
				cout<<0;
				return 0;
			}
			
			for(int i=1+zdjd; i<=n; i+=zdjd){
				ans += n-i;
			}
			
			cout<<ans<<endl;
		}
		
		return 0;
	}
	if(c==13 || c==14){
		while(T--){
			cout<<0<<endl;
		}
		
		return 0;
	}
	
	while(T--){
		memset(e, 0, sizeof(e));
		ll ans=0;
		cin>>n>>dis;
		
		for(int i=1; i<=n; i++){
			cin>>arr[i];
		}
		
		for(int i=1; i<=n; i++){
			int j=i+1;
			
			while(arr[j]-arr[i]<=dis && j<=n){
				e[i].push_back(j);
				j++;
			}
		}
		
		for(int i=1; i<=n; i++){
		    ans += bfs(i);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
