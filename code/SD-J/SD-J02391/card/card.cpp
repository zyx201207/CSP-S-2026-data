#include<bits/stdc++.h>
using namespace std;
int f[300010],a[500010],ans[300010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int>q;
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(q.top()!=a[j]){
					q.pop();
				}
				f[a[j]]=1;
			}else{
				q.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(q.size()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
