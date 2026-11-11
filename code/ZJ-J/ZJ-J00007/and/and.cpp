#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,mx,l;
set<int>st,s[35],cl;
map<int,int>cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		st.insert(x);
		cnt[x]++;
		for(int j=0;(1<<j)<=x;j++){
			if(x&(1<<j)){
				s[j].insert(x);
				mx=max(mx,j);
			}
		}
	}
	for(int j=mx;j>=0;j--){
		cl.clear();
		l=0;
		for(int x:s[j]){
			if(!st.count(x)){
				cl.insert(x);
			}else{
				l+=cnt[x];
			}
		}
		if(l>=m){
			ans+=(1<<j);
			for(int x:cl){
				s[j].erase(x);
			}
			cl.clear();
			for(int x:st){
				if(!s[j].count(x)){
					cl.insert(x);
				}
			}
			for(int x:cl){
				st.erase(x);
			}
		}
	}
	cout<<ans;
	return 0;
}

