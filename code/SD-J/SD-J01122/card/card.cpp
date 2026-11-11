#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],ans[M];
stack<int> st;
map<int,bool> mp;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==true){
				while(!a[st.empty()]&&a[st.top()]!=a[j]){
					mp[a[st.top()]]=false;
					st.pop();
				}
				st.pop();
			}
			st.push(j);
			mp[a[j]]=true;
		} 
		while(!st.empty()){
			int t=st.top();
			st.pop();
			ans[a[t]]++;
			mp[a[t]]=false;
		}
		for(int i=1;i<=m;i++){
			mp[i]=false;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
