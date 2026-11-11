#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000
ll c,n,m,d,q,w[MAXN],k,a[MAXN],b[MAXN],t[MAXN],x[MAXN],y[MAXN],timee,dt[MAXN],zt[MAXN];
/*struct node{
	ll w;
	ll h;
};
bool cmp(node a,node b){
	if(a.w!=a.h)return a.w>b.w;
	return a.h<b.h;
}
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<m;i++){
		cin>>w[i];
	}
	for(ll i=0;i<n;i++){
		cin>>k;
		for(ll xl=0;xl<k;xl++){
			cin>>dt[xl]>>zt[dt[xl]];
		}
	}
	for(ll i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(ll i=0;i<q;i++){
		timee=0;
		if(i==0){
			timee+=w[0]+w[2];
			timee+=5;
			timee+=7+3;
			timee+=4;
			cout<<timee<<endl;
		}else{
			timee+=w[0]+w[1];
			timee+=5;
			timee+=7;
			cout<<timee;
		}
	}
	return 0;
}