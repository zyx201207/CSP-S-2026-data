#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],pos[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	//求神机放我过 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j=pos[a[j]]+1) ans[a[j]]++;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
