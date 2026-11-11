#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000009,SN=5009;
ll a[N],nxt[N],n,x;
ll nd[SN][SN],num[SN][SN];
vector<ll> vans;
void solveN2(){
	for(ll i=1;i<=n;i++){
		nxt[i]=upper_bound(a+1,a+1+n,a[i]+x)-a-1;
	}
	for(ll len=2;len<=n;len++){
		for(ll l=1,r=len;r<=n;l++,r++){
			if(nxt[l]>=r){
				nd[l][r]=1;
				num[l][r]=1;
				continue;
			}
			if(nxt[l]==l||nd[nxt[l]][r]==-1){
				nd[l][r]=-1;
				num[l][r]=0;
				continue;
			}
			nd[l][r]=nd[nxt[l]][r]+1;
			num[l][r]=num[nxt[l]][r];
			if(nd[nxt[l]-1][r]==nd[nxt[l]][r])
			    num[l][r]+=num[nxt[l]-1][r];
			if(nd[nxt[l]-2][r]==nd[nxt[l]][r])
			    num[l][r]+=num[nxt[l]-2][r];
		}
	}
	ll ans=0;
	for(ll l=1;l+1<=n;l++){
		for(ll r=l+1;r<=n;r++){
			if(num[l][r]==2)ans++;
		}
	}
	vans.push_back(ans);
	for(ll i=1;i<=n;i++){
		a[i]=nxt[i]=0;
		for(ll j=1;j<=n;j++)nd[i][j]=num[i][j]=0;
	}
}
void solveA(){
	if(n==1)vans.push_back(0);
	else if(a[1]==a[2])vans.push_back(0);
	else{
		ll d=a[2]-a[1];
		ll num=x/d;
		ll len=2*num;
		if(num<=1)vans.push_back(0); 
		else vans.push_back(max(0LL,n-len+1));
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>x;
		for(ll i=1;i<=n;i++)cin>>a[i];
		if(c<=10)solveN2();
		else if(c<=12)solveA();
	}
//	freopen("migrate4.ans","r",stdin);
//	ll cnt=0;
	for(ll i=0;i<vans.size();i++){
		cout<<vans[i]<<"\n";
//		ll ac;
//		cin>>ac;
//		cout<<i<<" "<<vans[i]<<" "<<ac<<"\n";
//		cnt+=(vans[i]==ac);
	}
//	cout<<vans.size()<<" "<<cnt<<"\n";
	return 0;
}
