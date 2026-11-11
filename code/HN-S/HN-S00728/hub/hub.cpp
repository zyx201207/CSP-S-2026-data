#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e1+5;
int n,m,k;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;
		}
		int p=0;
		if(n%4==1||n%4==3)p=1;
		if(n%4==2)p=2;
		if(n%8!=0)p++;
		cout<<(n/8-k/4+p)<<'\n';
	}
	return 0;
}

