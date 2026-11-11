#include<bits/stdc++.h>
using namespace std;
const int N=500100;
queue<int> q;
int a[N],ans;
bool vis[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=m;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				vis[a[i]]++;
				if(vis[a[i]]==1){	
					q.push(a[i]);
				}else if(vis[a[i]]==2){
					for(int j=a[i];j<=n;j++){
						q.pop();
					}
					q.push(a[i]);
				}
			}
			if(q.front()==k){
				ans++;
			}else{
				for(int i=1;i<=n;i++){
					q.pop();
				}
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}

