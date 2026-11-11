#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans;
bool vis[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	int pos=31;
	while(pos>0){
		int res=0;
		for(int i=1;i<=n;i++){
			if(vis[i])
			res+=(a[i]>>(pos-1))%2;
		}
		if(res<m){
			pos--;
			continue;
		}
		for(int i=1;i<=n;i++){
			int k=(a[i]>>(pos-1))%2;
			if(k==0)
			vis[i]=0;
		}
	//	cout<<pos<<" "<<res<<'\n';
		pos--;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			ans=a[i];break;
		}
	}
	for(int i=1;i<=n;i++){
	//	cout<<vis[i]<<' ';
		if(vis[i]) ans&=a[i];
	}
	cout<<ans;
}
/*
0011
1111
1100
1100
*/
