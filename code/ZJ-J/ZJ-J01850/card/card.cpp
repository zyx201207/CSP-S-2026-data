#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		stack<int> s;
		for(int j=i;j<=n;++j){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				s.push(a[j]);
			}
			else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;++j){
			ans[j]+=vis[j];
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}
