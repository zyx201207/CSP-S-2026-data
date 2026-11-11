#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,m;
map<int,int> mp;
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<int> st;
	for(int i=1;i<=n;i++){
		map<int,int> mps;
		for(int j=i;j<=n;j++){
			if(mps[a[j]]){
				int s=st.back();
				st.pop_back();
				while(s!=a[j]&&!st.empty()){
					mps[s]--;
					s=st.back();
					st.pop_back();
				}
			}
			mps[a[j]]=i;
			st.push_back(a[j]);
		}
		while(!st.empty()){
			int s=st.back();
			cout<<s<<" ";
			st.pop_back();
			mp[s]++;
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
}