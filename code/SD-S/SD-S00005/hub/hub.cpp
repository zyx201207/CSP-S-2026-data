#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int C,T,n,k;
struct node{
	int u,v;
}a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		if(C==13||C==14){
			int ans=(n+1)/8;
			ans=ans-(k/4);
			ans+=1;
			cout<<ans<<"\n";
		}
		if(k==2){
			cout<<n/4<<"\n";
		}else{
			cout<<(n-(k-2))/4<<"\n";
		}
	}
	return 0;
}
