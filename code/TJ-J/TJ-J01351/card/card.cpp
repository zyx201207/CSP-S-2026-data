#include<bits/stdc++.h>
using namespace std;
bool b[300005];
stack<int> stk;
int a[500005];
int ans[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(stk.top()!=a[j]&&!stk.empty()){
					b[stk.top()]=false;
					stk.pop();
				}
				if(stk.size()) stk.pop();
			}
			stk.push(a[j]);
			b[a[j]]=true;
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
		for(int j=1;j<=m;j++){
			b[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
