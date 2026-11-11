#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		map<int,int>mp;
		stack<int>stk;
		for (int j=i;j<=n;j++){
			if (mp.count(a[j])){
				while (stk.size() && stk.top()!=a[j]) mp.erase(stk.top()),stk.pop();
			}
			stk.push(a[j]);
			mp[a[j]]++;
		}
		for (auto it:mp) ans[it.first]++;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

