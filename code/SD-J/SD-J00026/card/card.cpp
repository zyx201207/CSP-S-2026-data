#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],instk[300005];
stack<int>stk;
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(stk.size())stk.pop();
		for(int j=1;j<=m;j++)
		instk[j]=0;
		for(int j=i;j<=n;j++){
			if(instk[a[j]]){
				while(
				stk.size()&&stk.top()!=a[j] 
				){
					instk[stk.top()]=0;
					stk.pop();
				}if(stk.size())stk.pop();
			}stk.push(a[j]);
			instk[a[j]]=1;
		}for(int j=1;j<=m;j++){
			ans[j]+=instk[j];
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
