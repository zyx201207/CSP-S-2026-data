#include <bits/stdc++.h>//watashiwa 乐子 desu
using namespace std;
#define ll long long
const int N = 500015;
ll a[N],n,m,mx=INT_MIN,qzh[N],cf[N],cha;
bool cmp(ll aa,ll b){
	return aa>b;
}
void v1(){
	ll x=m/cha;
	if(x>n){
		cout<<n;
	}
	else cout<<x;
	return ;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool ff=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i>2&&((a[i-1]+cha)!=x)&&ff){//isn't A or B
			ff=0;
		}
		cha=x-a[i-1];
		a[i]=x;
	}
//	cout<<'\n'<<ff<<' '<<cha;
	sort(a+1,a+n+1,cmp);//back sort
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
		cf[i]=a[i]-a[i+1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<cf[i]<<' ';
//	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
	if(ff){//speA&B
		v1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll ans=0;
		for(int j=i+1;j<=n;j++){
			ans+=a[i]-a[j];
//			cout<<ans<<'\n';
			if(ans>m){
				mx=max(mx,(ll)(j-i-1));
//				cout<<(ll)(j-i)<<'\n';
				break;
			}
			if(ans==m){
				mx=max(mx,(ll)(j-i));
//				cout<<(ll)(j-i)<<'\n';
				break;
			}
		}
	}
	cout<<mx+1;
	return 0;
}//求你了t1别爆行不行QWQ