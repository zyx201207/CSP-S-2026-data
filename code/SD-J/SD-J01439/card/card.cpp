#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int M=3e5+5;
int a[N],cnt[M],n,m,vis[M],f;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>=a[i]) f=1; 
	}
	if(!f){
		for(int i=1;i<=m;i++) cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	
	return 0;
}
