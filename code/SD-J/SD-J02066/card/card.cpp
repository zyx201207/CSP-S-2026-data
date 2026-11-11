#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int N1=3e5+10;
int n,m;
int a[N];
int vis[N1];
int ans[N1];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					int t=s.top();
					vis[t]=0;
					s.pop();
				}
			}else{
				vis[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) ans[i]++;vis[i]=0;
		}
	}
	for(int i=1;i<m;i++) cout<<ans[i]<<' ';
	cout<<ans[m];
	return 0;
}
