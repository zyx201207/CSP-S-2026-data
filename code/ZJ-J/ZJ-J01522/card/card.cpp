#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<long long>a(n+1);
	vector<long long>vis(m+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<bool>v(m+1,false);
		stack<long long>st;
		for(int j=i;j<=n;j++){
			if(v[a[j]]==false){
				v[a[j]]=true;
				st.push(a[j]);
			}else{
				while(!st.empty()&&st.top()!=a[j]){
					v[st.top()]=false;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			vis[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
	return 0;
}