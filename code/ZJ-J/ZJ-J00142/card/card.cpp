#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
bool vis[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(vis[a[j]]&&!s.empty()){
					vis[s.top()]=0;
					s.pop();
				}
			}
			s.push(a[j]);
			vis[a[j]]=1;
		}
		while(!s.empty()){
			ans[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
return 0;
}