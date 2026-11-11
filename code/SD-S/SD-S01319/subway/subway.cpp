#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int M=5e5+10;
struct node{
	int a,t;
};
vector<node> v[N];
int n,m,k[N],c,d,q,aa,tt,w[M],x,y;
bool flag1=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			flag1=0;
		}
		for(int j=1;j<=k[i];j++){
			cin>>aa>>tt;
			v[i].push_back({aa,tt});
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<"\n";
	}
	return 0;
}
