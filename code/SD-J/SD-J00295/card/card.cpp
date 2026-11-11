#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],vis[10086],ma[10086];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]=1;
			}else{
				int t=st.top();
				if(t!=a[j]){
					vis[t]--;
					st.pop();
				}else{
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0) ma[j]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ma[i]<<" ";
	}
	return 0;
}
