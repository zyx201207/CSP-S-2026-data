#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int a[500005],ans[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		stack<int> stk;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(!stk.empty() && stk.top()!=a[j]){
					vis[stk.top()]=0;
					stk.pop();
				}
				if(stk.size())stk.pop();
			}
			stk.push(a[j]);
			vis[a[j]]=1;
		}
		while(stk.size()){
			ans[stk.top()]++;
			stk.pop();
		}
//		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
//Trick||Treat!
