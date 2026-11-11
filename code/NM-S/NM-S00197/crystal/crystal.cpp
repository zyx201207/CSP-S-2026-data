#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll chazhi[500005];
ll sz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n,m;
	cin>>n>>m;
	
//	ll shuzi=0;
//	bool flag=true;,tans=0
	for(ll i=1;i<=n;++i){
		cin>>sz[i];
	}
	
	
	sort(sz+1,sz+1+n);
	
	for(ll i=2;i<=n;++i){
		chazhi[i]=sz[i]-sz[i-1];
	}
	
	ll l=1,r=1,sc=1;
	ll cha=0;
	while(l<=r&&r<=n){
		if(cha<=m){
			r++;
			cha+=1LL*chazhi[r]*(r-l);
			if(cha<=m&&r<=n&&l<=r){
				sc=max(sc,r-l+1);
			}
		}else{
			cha-=(sz[r]-sz[l]);
			l++;
		}
//		cout<<l<<' '<<r<<' '<<cha<<'\n';
	}
	
	cout<<sc;
	
	return 0;
}
