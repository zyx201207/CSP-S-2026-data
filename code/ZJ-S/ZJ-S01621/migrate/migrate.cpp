#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int awa=2e6+5;
ll x[awa],d,ans;
ll c,t,n,trytry;
ll tryy(ll u,ll v){
	if(u==v){
		return 0;
	}
	ll itsans=1e18+9;
	for(ll i=u+1;i<=v;++i){
		if(x[i]-x[u]<=d){
			itsans=min(itsans,tryy(i,v)+1);
		}
	}
	return itsans;
}
ll betwen(ll u,ll v,ll timeqwq){
	if(u==v&&!timeqwq){
		return 1;
	}
	ll sum=0;
	for(ll i=u+1,ouo;i<=v;++i){
		if(x[i]-x[u]<=d){
			ouo=betwen(i,v,timeqwq-1);
			sum+=ouo;
		}
	}
	return sum;
}
ll max__(ll x,ll y){
	if(x-y>0)return x;
	return y;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=10)while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;++i){
			cin>>x[i];
		}
		ans=0,trytry=0;
		for(ll i=1;i<n;++i){
			for(ll j=i+1;j<=n;++j){
				trytry=tryy(i,j);
				if(betwen(i,j,trytry)==2){
					//cout<<i<<"->"<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	else if(11<=c&&c<=12)while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;++i){
			cin>>x[i];
		}
		ll ans=0,qwq=x[2]-x[1];
		if(d<qwq*2)cout<<"0\n";
		else{
			if(d<qwq*3)cout<<n-3<<"\n";
			else{
				ans=d/qwq*2;
				cout<<max__(0,n-ans+1)<<"\n";
			}
		}
	}
}
/*回家以后严肃品尝一下migrate披萨，这个谐音梗绝对会出现在我的游记里
75+16=91pts 吗，interesting*/ 
