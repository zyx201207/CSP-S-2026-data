#include<bits/stdc++.h>

using namespace std;

const int M=3e5+5,N=5e5+5;

int a[N];
int ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];

	for(int i=1;i<=n;i++){
		deque<int> q;
		vector<bool> vis(M,0);
		vector<bool> pd(M,0);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(q.back()!=a[j]){
					vis[q.back()]=false;
					q.pop_back();
				}
			}
			else{
				q.push_back(a[j]);
				vis[a[j]]=true;
			}

			while(q.size()){
				if(!pd[q.back()])ans[q.back()]++;
				pd[q.back()]=false;
				q.pop_back();

			}
		}
	}

	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}

	return 0;
}