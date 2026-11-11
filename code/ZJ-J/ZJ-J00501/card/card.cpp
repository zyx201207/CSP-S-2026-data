#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005],m;
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int> mp;vector<int> st;
		for(int j=i;j<=n;j++){
			int f=1;
			for(auto t:st){
				if(a[j]==t){
					f=0;
					while(a[j]!=st[st.size()-1]){
						mp[st[st.size()-1]]--;
						st.pop_back();
					}
					break;
				}
			}
			if(f){
				st.push_back(a[j]);
				mp[a[j]]++;
			}
		}
		for(auto t:mp){
			if(t.second!=0){
				ans[t.first]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
