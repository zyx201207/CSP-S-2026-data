#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m,a[N],ma[N],ans[N];
stack<int> q;
int main() {
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		while(!q.empty()) q.pop();memset(ma,0,sizeof ma);
		for(int j=i;j<=n;j++) {
			if(ma[a[j]]==0) q.push(a[j]),ma[a[j]]=1;
			else {
				while(q.top()!=a[j]){
					int t=q.top();ma[t]=0;q.pop();
				}
			}
		}
		for(int j=1;j<=m;j++) {if(ma[j]!=0) ans[j]++;}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
