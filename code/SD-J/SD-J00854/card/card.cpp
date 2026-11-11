#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],v[N];
int ans[N];
stack<int> q;
//正着消，反着消相同 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]!=i){
				v[a[j]]=i;
				q.push(a[j]);
			}else{
				while(q.top()!=a[j]){
					v[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}

	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0; 
} 

