#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int c,t,n,k,u[N],v[N];
void code(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
	}
	if(k==n){
		cout<<0;
		return ;
	}
	if(13<=c&&c<=14){
		int m=n>>1;
		if(k>m){
			cout<<1;
		}else{
			cout<<((((m-k)+3)>>1)>>1)+1;
		}
		return ;
	}
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		code();
		cout<<'\n';
	}
	return 0;
}
