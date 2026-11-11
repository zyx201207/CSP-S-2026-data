#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=3e5+3;
int n,m,a[N],ans[M];
bool in[M];
stack<int> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(in[a[j]]){
				while(stk.top()!=a[j]){
					in[stk.top()]=0;
					stk.pop();
				}
				stk.pop();
			}
			stk.push(a[j]);
			in[a[j]]=1;
		}
		while(stk.size()){
			++ans[stk.top()];
			in[stk.top()]=0;
			stk.pop();
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}

