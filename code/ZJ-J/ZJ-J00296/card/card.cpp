#include<bits/stdc++.h>
using namespace std;

deque<int> q;
int n,m,a[500005],vis[300005],ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
//				cout << j << endl;
				while(a[q.back()]!=a[j]){
					vis[a[q.back()]] = 0;
//					cout << a[q.back()] << " ";
					q.pop_back();
				}
//				cout << a[q.back()] << endl;
				q.pop_back();
				q.push_back(j);
//				cout << vis[2] << endl;
			}
			else{
				q.push_back(j);
				vis[a[j]] = 1;
			}
		}
		while(!q.empty()){
			ans[a[q.back()]]++;
//			cout << i << " " << a[q.back()] << endl;
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

