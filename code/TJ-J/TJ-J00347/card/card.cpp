#include<bits/stdc++.h>
using namespace std;
stack<int>q;
int a[500005],ans[200005];
int t[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=n;
	while(num--){
		for(int i=(n-num);i<=n;i++){
			if(q.empty()||t[a[i]]==0){
				q.push(a[i]);
				t[a[i]]++;
			}
			else{
				while(q.top()!=a[i]){
					if(t[q.top()]==1){
						t[q.top()]--;
					}
					q.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]==1) ans[i]++; 
		} 
		memset(t,0,sizeof(t));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
