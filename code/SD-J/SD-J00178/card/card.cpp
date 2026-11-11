#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m,a[N];
bool vis[N];
int res[N];
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				dq.push_back(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(!dq.empty()){
					int u=dq.back();
					dq.pop_back();
					vis[u]=false;
					if(u==a[j]) break;
				}
				dq.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) res[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}


