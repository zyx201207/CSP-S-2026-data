#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sz[200005];

ll n,m;

bool cmp(ll a,ll b){
	return a>b;
}

//ll abc(ll a,ll b){
////	cout<<a<<' '<<b<<' '<<(a&b)<<'\n';
//	return (a&b);
//}
//
//void dfs(ll idx,ll cnt,ll pos){
//	if(cnt==0||sz[idx]==0){
//		return ;
//	}
//	if(idx==n){
//		if(pos==m){
//			ans=max(ans,cnt);
//		}
////		cout<<cnt<<'\n';
//		
//		return ;
//	}
//	
////	for(ll i=1;i<=n;++i){
//	ll a=sz[idx];
////	cout<<a<<' '<<cnt<<' '<<(cnt&a)<<'\n';
//	dfs(idx+1,abc(cnt,a),pos+1);
//	dfs(idx+1,cnt,pos);
////	}
//}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	ll ans=0;
	
	cin>>n>>m;
	
	bool flag=true;
	for(ll i=1;i<=n;++i){
		cin>>sz[i];
		if(flag&&i!=1&&sz[i]!=sz[i-1]){
			flag=false;
		}
	}
	
	if(flag){
		cout<<sz[1];
		return 0;
	}
	
	if(m==1){
		sort(sz+1,sz+1+n);
		cout<<sz[n];
		return 0;
	} 
	
	if(m==n){
		ll cnt=sz[1];
		for(ll i=2;i<=n;++i){
			cnt&=sz[i];
		}
		
		cout<<cnt;
		return 0;
	}
	
//	for(ll i=1;i<=n;++i){
//		ll cnt=sz[1];
//		for(ll i=2;i<=n;++i){
//			cnt&=sz[i];
//		}
//		
//		cout<<cnt<<'d';
//		return 0;
//	}
	
	sort(sz+1,sz+1+n,cmp);
	ans=sz[1];
//	cout<<ans;
	for(ll i=2;i<=m;++i){
		ans&=sz[i];
	}
	
//	if(n<=20){
////		ll idx=1,cnt=0;
////		dfs(1,2147483648,1);
////		cout<<(1&3);
//	}
	
	cout<<ans;
	
	return 0;
}
