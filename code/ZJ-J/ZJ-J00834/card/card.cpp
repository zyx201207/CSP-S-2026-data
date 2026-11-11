#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		set<int> s;
		for(int j=i;j<=n;j++){
			if(s.find(a[i])!=s.end()){
				while(st.size()&&st.top()!=a[i]){
					int x=st.top();
					st.pop();
					s.erase(x);
				}
			}
			else{
				st.push(a[i]);
				s.insert(a[i]);
			}
		}
		while(st.size()){
			int x=st.top();
			cnt[x]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
