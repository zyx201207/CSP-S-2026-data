#include<bits/stdc++.h>
using namespace std;
#define int long long
stack<int> st;
const int N = 2e5+5;
int s[N];
int ans[N];
bool flag[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!flag[s[j]]) {
				st.push(s[j]);
				flag[s[j]] = true;
			}
			else{
				while(!st.empty()&&st.top()!=s[j]){
					flag[st.top()]=false;
					st.pop();
				}
				if(st.top()==s[j]){
					flag[s[j]]=false;
					st.pop();
				}
				st.push(s[j]);
				flag[s[j]]=true;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			flag[st.top()]=false;
			st.pop();
		}
	}
	bool is=true;
	for(int i=1;i<=m;i++){
		if(is){
			cout<<ans[i];
			is = false; 
		}
		else cout<<' '<<ans[i];
	}
	return 0;
}
