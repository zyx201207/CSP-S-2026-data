#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],flaga=0,ans[514514];
bool vis[514514]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
//	cout<<n<<' '<<m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flaga=1; 
	}
	if(flaga==0){
		for(int i=1;i<=n;i++) if(a[i+1]>a[i]) cout<<i<<' '; 
	}
	else{
		for(int i=1;i<=n;i++){
			stack<long long> st;
			for(int j=i;j<=n;j++){
				if(vis[a[j]]==0){
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
			while(!st.empty()){
				vis[st.top()]=0;
				ans[st.top()]++;
				st.pop();
			}
		} 
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	} 
	return 0;
}