#include<bits/stdc++.h>
using namespace std;
//#define int long long
//signed main()
const int N=5e5+5;
int ans[N];
map<int,int> mp;
stack<int> s;
int a[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(vis[a[i]]) continue;
			vis[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) cout<<n-vis[i]+1<<" ";
			else cout<<0<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(s.size()) s.pop();
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(s.size()){
					int t=s.top();
					if(t==a[j]){
						s.pop();
						break;
					}
					mp[t]=0;
					s.pop();
				}
				s.push(a[j]);
				mp[a[j]]++;
			}
			else{
				s.push(a[j]);
				mp[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

