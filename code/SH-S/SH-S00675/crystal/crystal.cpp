#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll sum[500010],ssum;
bool flag;
ll dd;
struct node{
	ll a,d;
}o[500010];
bool sort1(node a,node b){
	return a.d<b.d;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>o[i].a;
	}
	ll dd=o[2].a-o[1].a;
	for(ll i=3;i<=n;i++){
		if(o[i].a-o[i-1].a!=dd){
			flag=1;
			break;
		}
	}
	if(!flag){
		for(ll i=1;i<=n;i++){
			if((i-1)*i*dd/2>m){
				cout<<i-1<<endl;
				return 0; 
			}
		}
	}
	else{
		bool fflag=0;
		sort(o+1,o+n+1,sort1);
		for(ll i=1;i<n;i++){
			o[i].d=o[i+1].a-o[i].a;
		}
		o[n].d=0x3f3f3f3f3f3f3f3f;
		for(ll i=1;i<=n;i++){
			sum[i]=sum[i-1]+o[i].d;
		}
		for(ll i=1;i<=n;i++){
			ssum=0; 
			for(ll j=1;j<=i;j++){
				ssum=0;
				for(ll k=i;k>=j;k--){
					ssum+=sum[k]-sum[j-1]; 
				}
				if(ssum>m){
					cout<<i<<endl;
					fflag=1;
					break;
				}
			}
			if(fflag) break;
		}
	}
	return 0;
}
