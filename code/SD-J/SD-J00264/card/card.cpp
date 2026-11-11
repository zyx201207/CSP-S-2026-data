#include<bits/stdc++.h>
using namespace std;
int a[500010];
int point[300010];
int ans[300010];
stack<int>stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=true;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=false;
		}
	}
	if(flag&&n>=200000){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(!stk.empty()){
			stk.pop();
		}
		for(int j=i;j<=n;j++){
			if(point[a[j]]==1){
				while(stk.top()!=a[j]){
					point[stk.top()]=0;
					stk.pop();
				}
				continue;
			}
			point[a[j]]=1;
			stk.push(a[j]);
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			point[stk.top()]=0;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

