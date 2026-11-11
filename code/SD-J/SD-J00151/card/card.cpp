#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=5e5+5,MAX=1e18,MIN=-1e18;
int a[N];
bool vis[N];
int viss[N];
stack<int> st;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				st.push(a[j]);
			}else{
				while(!st.empty()){
					if(st.top()==a[j]){
						break;
					}
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				viss[j]++;
			}
		}
		memset(vis,0,sizeof(vis));
		while(!st.empty()){
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<viss[i]<<" ";
	}
}
signed main(){
	IOS
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
