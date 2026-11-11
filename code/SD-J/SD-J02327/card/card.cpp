#include<bits/stdc++.h>
using namespace std; 
int n,m;
int a[500005];
int ans[300005];
bool up=1;
void out(){
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]++;
		if(a[i]<a[i-1]) up=0;
	}
	if(up){
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;i++){
			ans[a[i]]=max(ans[a[i]],i);
		}
		out();
	}
	else{
		ans[a[n]]=n;
		out();
	}
	return 0;
}
