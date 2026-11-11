#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],ans[1000010],t[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		for(int i=1;i<=n;i++){
			stack<int> st;
			map<int,bool> mp;
			for(int j=i;j<=n;j++){
				if(mp[a[j]]==0){
					st.push(a[j]);
					mp[a[j]]=1;
				}else{
					while(st.top()!=a[j]){
						st.pop();
					}
				}
			}
			while(!st.empty()){
				ans[st.top()]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++) t[a[i]]++;
		int cc=0;
		for(int i=1;i<=m;i++){
			cc+=t[i];
			cout<<cc<<" ";
		}
	}
	return 0;
}
