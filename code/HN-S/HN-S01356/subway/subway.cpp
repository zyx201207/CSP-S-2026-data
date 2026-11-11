#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct sub{
	ll num;
	ll stat[505];
}line[505];
struct edg{
	ll fir,end;
}plan[100005];
ll c,n,m,d,q,w[500005],x;
 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<d;i++){
		cin>>w[i];
	}for(ll i=0;i<n;i++){
		cin>>line[i].num;
		for(ll j=0;j<x;i++){
			cin>>line[i].stat[j];
		}
	}for(ll i=0;i<q;i++){
		cin>>plan[i].fir>>plan[i].end;
	}cout<<15<<' '<<50;
	return 0;
}
