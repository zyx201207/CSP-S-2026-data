#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,c[114514<<1];
int ans[114514<<1];
int f[114514<<1];
stack<int>stk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
//		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[c[j]]){ 
				int cur=-1;
				while(cur!=c[j]){
					cur=stk.top();
					stk.pop();
					f[cur]--;
				}
			}
			f[c[j]]++;
			stk.push(c[j]);
		}
		while(!stk.empty()){
			f[stk.top()]--;
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
	return 0;
}

