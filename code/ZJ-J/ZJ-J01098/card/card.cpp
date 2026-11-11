#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,e[500010],a[500010],f[500010];
stack<int>q;
bool check(){
	int i;
	for(i=2;i<=n;i++)
		if(a[i]<a[i-1]) return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(check()){
		for(i=1;i<=n;i++) e[a[i]]=i;
		for(i=1;i<=m;i++) cout<<e[i]<<" ";
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(q.top()!=a[j]){
					f[q.top()]=0,q.pop();
				}
				q.pop();
				q.push(a[j]);
			}else q.push(a[j]),f[a[j]]=1;
		}
		while(!q.empty()) e[q.top()]++,f[q.top()]=0,q.pop();
	}
	for(i=1;i<=m;i++) cout<<e[i]<<" ";
	return 0;
}
/*
pts=52
ÆÀ²â»ú±£ÓÓÎÒ 
*/
