#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],vis[N],ans[N]; 
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==1){
				while(1){
					int t=st.top();
					st.pop();
					if(t==a[i]){
						st.push(t);
						break;
					}
					else{
						vis[t]=0;						
					}
				}
			}
			else{
				st.push(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		while(!st.empty()){
			ans[st.top()]+=1;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

