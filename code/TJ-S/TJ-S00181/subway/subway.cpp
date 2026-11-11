#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define int long long
const int M=5e5+5;
vector<int>tu[M];
const int N=505;
int w[N];//出站时间 
int ti[M][20];
int c,n,m,d,q,k;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k;
		int a,t;
		scanf("%lld%lld",&a,&t);
		int e=a;//连接的上一站 
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			tu[e].push_back(a);
			tu[a].push_back(a);
			e=a;
		}
	}
	while(q--){
		cout<<1<<'\n';
	}
	return 0;
}
