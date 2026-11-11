#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<int,int> ans;
	for(int k=1;k<=n;k++){
		map<int,int> mp;
		stack<int> st;
		for(int i=k;i<=n;i++){
			if(mp[a[i]]==0){
				st.push(a[i]);
				mp[a[i]]=1;
			}else{
				while(!st.empty()){
					int x=st.top();
					if(x!=a[i]){
						mp[x]=0;
						st.pop();
					}else{
						st.pop();
						break;
					}
				}
				st.push(a[i]);
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
