#include <bits/stdc++.h>
using namespace std;
int n,m;
bool flag=true;
int arr[500005],ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
		if(arr[i]<arr[i-1]) flag=false;
	}
	if(flag) {
		for(int i=1; i<=n; i++) {
			if(arr[i]<arr[i+1]||i==n) {
				cout<<i<<" ";
			}
		}
	} else {
		if(n<=5000) {
			for(int i=1; i<=n; i++) {
				stack<int> q;
				bool hq[300005];
				while(!(q.empty())) q.pop();
				for(int j=1; j<=m; j++) {
					hq[j]=false;
				}
				for(int j=i; j<=n; j++) {
					if(!(hq[arr[j]])) {
						hq[arr[j]]=true;
						q.push(arr[j]);
					} else {
						while(!(q.empty())) {
							int v=q.top();
							q.pop();
							hq[v]=false;
							if(v==arr[j]) break;
						}
						hq[arr[j]]=true;
						q.push(arr[j]);
					}
				}
				for(int j=1; j<=m; j++) {
					if(hq[j]){
						ans[j]++;
					}
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<" ";
			}
		}else{
			for(int i=1;i<=n;i++){
				ans[arr[i]]++;
			}
			ans[arr[n]]=n;
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<" ";
			}
		}
	}
	return 0;
}
