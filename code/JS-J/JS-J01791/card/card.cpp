#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m,a[N],ans[N];
stack<int> stk;
bool vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n;++i){
		memset(vis,0,sizeof(vis));
		while(!stk.empty()) stk.pop();
		for(int j = i;j <= n;++j){
			if(vis[a[j]]){
				while(stk.top() != a[j]){
					vis[stk.top()] = false;
					stk.pop();
				}
			}else{
				vis[a[j]] = true;
				stk.push(a[j]);
			}
		}
		for(int i = 1;i <= n;++i){
			if(vis[i]){
				ans[i] += 1;
			}
		}
	}
	for(int i = 1;i <= m;++i){
		printf("%lld ",ans[i]);
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
