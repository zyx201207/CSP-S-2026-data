#include<bits/stdc++.h> 
using namespace std;
int a[5000005];
int ans[5000005];
bool vis[5000005]={0};
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int ii=1;ii<=n;ii++) vis[ii]=0;
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==true){
				while(!s.empty()){
					if(s.top()==a[j]){
						vis[s.top()]=false;
						s.pop();
						break;
					}
					s.pop();
				}
			}
			s.push(a[j]);
			vis[a[j]]=true;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
