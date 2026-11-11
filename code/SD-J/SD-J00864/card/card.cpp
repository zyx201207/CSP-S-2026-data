#include<bits/stdc++.h>
using namespace std;
int Last[300005],ans[300005];
int v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		Last[v[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[v[j]] ++;
			j=Last[v[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
