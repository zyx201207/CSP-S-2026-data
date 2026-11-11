#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxx=5e5+10;
const int maxa=3e5+10;
int a[maxx],vis[maxa],ans[maxa];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		stack<int>st;
		for(i=1;i<=m;i++){
			vis[i]=0;
		}
		for(i=t;i<=n;i++){
			if(vis[a[i]]==0){
				st.push(a[i]);
				vis[a[i]]=1;
			}
			else{
				while(st.size()&&st.top()!=a[i]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(st.size()){
			ans[st.top()]++;
			vis[st.top()]=0;
			st.pop();
		} 
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
