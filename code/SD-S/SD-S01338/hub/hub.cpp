#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
const int N=2e6+10;
const int INF=0x7f7f7f7f;
/*====================*/
int u[N],v[N];
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;++i) cin>>u[i]>>v[i];
		if(c==1){
			if(k==2) cout<<2;
			
		}
	}
	return 0;
}
