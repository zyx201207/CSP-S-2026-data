#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define fst ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N];
map<int,int> s,mp;
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()) st.pop();
		for(int i=1;i<=m;i++) mp[i]=0;
		for(int j=i;j<=n;j++){
			mp[a[j]]++;
			st.push(a[j]);
			if(mp[a[j]]>1){
				mp[a[j]]--;
				st.pop();
				while(st.top()!=a[j]){
					mp[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			s[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
