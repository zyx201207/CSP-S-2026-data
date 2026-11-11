#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll a[N],dif[N];
ll mul[N];
ll n,m,ans=-1;
bool cmp(ll x,ll y) {
	return x>y;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(n==1) {
		cout<<1;
		return 0;
	}
	bool A=0,B=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<-100||a[i]>100)B=1;
	}
	sort(a+1,a+1+n,cmp);
	//m=0
	if(m==0) {
		map<ll,ll> mp;
		for(int i=1; i<=n; i++) {
			mp[a[i]]++;
			ans=max(ans,mp[a[i]]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1; i<n; i++) {
		dif[i]=a[i+1]-a[i];
		if(i!=1&&dif[i]!=dif[i-1])A=1;
	}
	if(!A) {//性质A
		ll d=a[1]-a[2];
		mul[1]=0;
		for(int i=2; i<=n; i++)
			mul[i]=mul[i-1]+d*i;
		for(int i=1; i<=n; i++)
			if(mul[i]>m) {
				cout<<i-1;
				return 0;
			}
		cout<<n;
		return 0;
	} else if(!B&&n>=5000) {//B?
		cout<<n;
		return 0;
	} else {
		ll tmp=0,cnt=0;
		for(int i=1; i<n; i++) {
			tmp=0,cnt=1;
			for(int j=i+1; j<=n; j++) {
				tmp=tmp+(a[i]-a[j]);
				if(tmp>m)break;
				cnt++;
			}
			if(cnt==n) {
				cout<<cnt;
				return 0;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
/*
6 4
1 2 3 4 5 6

5 10
1 3 5 7 9

*/
//	if(!A) {
//		for(int i=1;i<=n;i++){
//			if(1LL*i*(i-1)/2)
//		}
//	}
//	cout<<"i"<<i<<"\n";
//	cout<<a[i]<<" "<<a[j]<<"\n";
//	cout<<"tmp:"<<tmp<<"\n";

/*

5 10
7 2 -5 -1 10



先敲n^2
再打特殊性质B
注意到B包含A
T1 90pts


注意：
变量名是否关键字
n,m别写反
空间时间
long long
冷静
珍惜时间

*/
