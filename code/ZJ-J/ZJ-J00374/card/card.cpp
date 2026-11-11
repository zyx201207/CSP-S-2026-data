#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],vis[300010],ans[300010];
int solve1(){
	int i,j;
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++){
		stack<int>st;
		memset(vis,0,sizeof(vis));
		for(j=i;j<=n;j++){
			if(!vis[a[j]])st.push(a[j]),vis[a[j]]=1;
			else{
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
}
bool checkA(){
	int i,j;
	for(i=1;i<n;i++){
		if(a[i]>a[i+1])return false;
	}
	return true;
}
void solve2(){
	int i,j;
	for(i=n;i>=1;i--){
		if(a[i]==a[i+1])continue;
		ans[a[i]]=i;
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
}
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	if((n<=500)&&(m<=200))solve1();
	else if(checkA())solve2();
	return 0;
}
