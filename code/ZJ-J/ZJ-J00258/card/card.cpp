#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=3e5+10;
int a[N],ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
		//cout<<endl;
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]){
					int x=st.top();
					vis[x]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(st.size()){
			int u=st.top();
			ans[u]++;
			st.pop();
			vis[u]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

