#include<bits/stdc++.h>
typedef long long ll;
typedef pair<int,int> PII;
using namespace std;
const int N=505,M=5e5+5;
vector<PII>a[N];
inline void init(){
	memset(f,0xcf,sizeof f);
}
inline void sub1(){
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);init();
	int opt,n,m,d,q;
	cin>>opt>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int s,t;
			cin>>s>>t;
			a[i].push_back(s,t);
		}
	}
	for(int i=1;i<=r;i++)cin>>q[i];
	if(opt<=6){
		sub1();
	}
	return 0;
}
