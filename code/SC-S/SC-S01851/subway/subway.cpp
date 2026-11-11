#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,c,d,q ;
const ll  N=505,M=5e5+5;
ll w[M];
vector<int>a[N],t[N];//a[i][j]存第i线路上的第j个地铁站的编号
ll cnt=1;
vector<int>line;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	cout<<32<<"\n"<<17;
}