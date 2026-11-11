#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
unordered_map<int,bool>mp;
int n,m,a[N],cnt[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int>st;
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			int now=a[i];
			if(mp[now]!=0){
				while(!st.empty()){
					int tp=st.top();
					mp[tp]=0;
					if(tp==now){
						st.pop();
						break;
					}
					st.pop();
				}
				st.push(now);
				mp[now]=1;
			}
			else{
				mp[now]=1;
				st.push(now);
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			mp[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
}
