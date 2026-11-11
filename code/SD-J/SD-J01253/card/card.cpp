#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
bool v[300010];
int ans[300010];
stack<int> p;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int T=1;T<=n;T++){
		for(int i=1;i<=m;i++){
			v[i]=0;
		}
		for(int i=T;i<=n;i++){
			if(v[a[i]]==0){
				v[a[i]]=1;
				p.push(a[i]);
			}else{
				while(p.top()!=a[i]){
					v[p.top()]=0;
					p.pop();
				}
			}
		}
		while(!p.empty()){
			ans[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

