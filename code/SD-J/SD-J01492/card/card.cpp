#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
int ans[N],a[N];
bool vis[N];
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	while(i<=n){
		fill(vis+1,vis+n+1,0);
		for(int j=i;j<=n;j++){
			dq.push_back(a[j]);
			if(vis[a[j]]){
				int k=0;
				while(!dq.empty()&&k!=j){
					dq.pop_front();
					k++;
				}
			}
			vis[a[j]]=true;
		}
		while(!dq.empty()){
			ans[dq.front()]++;
			dq.pop_front();
		}
		i++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
