#include<bits/stdc++.h>
using namespace std;
priority_queue<int>a[300010];
int n,m,ans[300010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[b[i]].push(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[b[j]]=ans[b[j]]+1;
			j=a[b[j]].top();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}