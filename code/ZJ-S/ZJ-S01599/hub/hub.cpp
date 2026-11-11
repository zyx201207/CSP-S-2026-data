#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=1e6+10;
int c,T,n,K,x,y;
vector<int> a[N];
void Clear(){
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
}
void Main(){
	Clear();
//	cin>>n>>K;
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<=n-1;i++){
//		cin>>x>>y;
		scanf("%lld%lld",&x,&y);
		a[x].pb(y);
		a[y].pb(x);
	}
	if(K==2){
		if(n==2){
//			cout<<1<<"\n";
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		return;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		Main();
	}
	return 0;
}
