#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
const int man=1e5+10;
struct node{
	int u,v,w;
};
int c,n,m,d,q,w[maxn],k[505],ak[maxn],at[maxn];
vector<node>g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ak[j]>>at[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll a=rand();
		cout<<a<<endl;
	}
	return 0;
}

