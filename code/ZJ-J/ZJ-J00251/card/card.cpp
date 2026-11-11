#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans[N];
map<int,int> mp;
stack<int> stk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(stk.top()!=a[j]){
					mp[stk.top()]--;
					stk.pop();
				}
			}
			else{
				mp[a[j]]=1;
				stk.push(a[j]);
			}
		}
		for(auto i:mp){
			if(i.second){
				ans[i.first]++;
			}
			mp[i.first]=0;
		}
		while(stk.size()) stk.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
