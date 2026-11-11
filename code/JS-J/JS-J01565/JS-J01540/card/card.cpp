#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,m,a[500010],vis[5010],tong[300010];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
				vis[a[j]]=1;
			}else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(st.size()){
			tong[st.top()]++;
			st.pop();
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
