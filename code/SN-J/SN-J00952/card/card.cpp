#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],vis[500005];
ll sum[500005];
stack<int> b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++) vis[k]=0;
		for(int k=i;k<=n;k++){
			if(!b[a[k]].empty()&&vis[b[a[k]].top()]!=1){
				for(int j=b[a[k]].top()+1;j<k;j++){
					vis[j]=1;
					b[a[k]].pop();
				}
			}
			else if(!b[a[k]].empty()&&vis[b[a[k]].top()]==1) b[a[k]].pop();
			b[a[k]].push(i);
		}
		for(int k=1;k<=m;k++){
			if(!b[k].empty()&&vis[b[k].top()]!=1){
				sum[k]++;
				b[k].pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
