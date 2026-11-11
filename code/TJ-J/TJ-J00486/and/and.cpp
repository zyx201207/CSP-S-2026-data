#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll LOG=20;
const ll MAXN=2e5+99;
ll a[MAXN];
ll cnt[LOG];
ll cal(){
	ll res=0;
	for(int k=0;k<LOG;k++){
		if(cnt[k]==0){
			res+=(1<<k);
		}
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	
	if(m==1){
		cout<<mx<<endl;
	}else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i]; 
		}
		cout<<ans<<endl;
	}else if(m==2){
		ll imx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					imx=max(imx,a[i]&a[j]);
				}
			}
		}
		cout<<imx<<endl;
	}else if(m==n-1){
		for(int i=0;i<LOG;i++){
			cnt[i]=n;
		}
		for(int i=1;i<=n;i++){
			for(int k=0;k<LOG;k++){
				if(a[i]&(1<<k)){
					cnt[k]--;
				}
			}
		}
		ll ans=-1;
		for(int i=1;i<=n;i++){
			vector<ll> add;
			for(int k=0;k<LOG;k++){
				if(!(a[i]&(1<<k))){
					add.push_back(k);
					cnt[k]--;
				}
			}
			ll res=cal();
			if(res<=MAXN){
				ans=max(ans,cal());
			}
			for(int j=0;j<add.size();j++){
				cnt[j]++;
			}
		}
		cout<<ans<<endl;
	}else if(mx<=3){
		ll two=0,one=0;
		for(int i=1;i<=n;i++){
			if(a[i]==2){
				two++;
			}else if(a[i]==1){
				one++;
			}
		}
		if(two>=m){
			cout<<2<<endl;
		}else if(one>=m){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else if(n>20){
		bool B=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				B=false;
				break;
			}
		}
		if(B){
			ll ans=a[n];
			for(int i=n-1;i>=n-m+1;i--){
				ans=ans&a[i];
			}
			cout<<ans<<endl;
			return 0;
		}
		//A
		bool A=true;
		map<ll,bool> mp;
		for(int k=0;k<LOG;k++){
			mp[(1<<k)]=true;
		}
		for(int i=1;i<=n;i++){
			if(!mp[a[i]]){
				A=false;
				break;
			}
		}
		if(A){
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
			return 0;
		}
	}
	vector<ll> v;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	ll ans=-1;
	do{
		ll tmp=a[v[0]];
		for(int i=1;i<m;i++){
			tmp=tmp&(a[v[i]]);
		}
		ans=max(ans,tmp);
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans<<endl;
	return 0;
} 
/*
5 4
3 4 5 6 7

21 3
1 2 4 8 1 2 4 8 1 2 4 8 1 2 4 8 1 2 4 8 1



21 3
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/ 
