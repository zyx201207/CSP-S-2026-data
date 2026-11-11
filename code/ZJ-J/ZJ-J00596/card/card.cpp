#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100,M=100;
int n,m,a[N],ans[N],ct=1,vis[N];
stack<int> sta;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				sta.push(a[i]);
			}else{
				while(sta.size()&&sta.top()!=a[i]){
				vis[sta.top()]=0;
				sta.pop();
			}
			}
		}
		while(sta.size()){
			ans[sta.top()]++;
			vis[sta.top()]=0;
			sta.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
