#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],ans[1000005],m;
stack<int>st;
map<int,bool>mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(mp[a[j]]&&st.size()){
				mp[st.top()]=0;
				st.pop();
			}
			st.push(a[j]);
			mp[a[j]]=1;
		}
		while(st.size()){
			mp[st.top()]=0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
