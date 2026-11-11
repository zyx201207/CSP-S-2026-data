// Think TWICE
// Code ONCE
// NEVER FORGET YOUR 143pts IN NOIP 2025
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(int)(r);++i)
#define pb emplace_back

void file(string fl){
	 freopen((fl+".in").c_str(),"r",stdin);
	 freopen((fl+".out").c_str(),"w",stdout);
}

ll ksm(ll a,ll b,ll p){
	ll ret=1%p;
	while(b){
		if(b&1)ret=ret*a%p;
		a=a*a%p;
	}
	return ret;
}

constexpr int N=5e5+7;

ll n,m,a[N],sum[N],ans;

int main(){
	file("crystal");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		cin>>n>>m;
		up(1,n,i)cin>>a[i];sort(a+1,a+n+1);
		up(1,n,i)sum[i]=sum[i-1]+a[i];
		up(1,n,i){
			ll l=1,r=i,mid,_ans=0;
			while(l<=r){
				mid=(l+r)>>1;
				ll s=sum[i]-sum[i-mid];
				//cout<<mid<<' '<<s<<'\n';
				if(a[i]*mid-s<=m)_ans=max(_ans,mid),l=mid+1;
				else r=mid-1;
			}
			//cout<<"qwq "<<i<<' '<<_ans<<'\n';
			ans=max(ans,_ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
14:44 done
*/
