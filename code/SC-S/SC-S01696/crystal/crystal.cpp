#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5*1e5+2;

ll a[N],cnt[N];
ll ans[N];

bool cmp(ll x,ll y){
	return x>y;
}

/*
哈哈哈

一直在和特殊性质B互相肘击

没时间看后面了哈哈哈

其实后面也看不懂呢哈哈哈

哈哈哈

还是不能场切橙呢

哈哈哈

退役了

哈哈哈

这个屏幕vga根本插不紧呢

一直黑屏呢

哈哈哈哈

哈哈哈

LuoGU大号 Sxhx2011
小号 sxhx_second
*/


//井include<bits\stdc++.h>
//freopen
//我常常追忆过去

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	ll n,M;
	cin>>n>>M;
	
	bool PianFen1=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) PianFen1=0;
		cnt[a[i]]++;
	}
	
	if(n==1){cout<<1<<'\n';return 0;}
	
	if(M==0){
		ll ans=0;
		for(ll i=1;i<=n;i++) ans=max(ans,cnt[a[i]]);
		cout<<ans<<'\n';
		return 0;
	}
	
	if(PianFen1){
		ll cnt=n*(n-1)/2;
		if(M==0){cout<<1<<'\n';return 0;}
		else if(M==1){cout<<2<<'\n';return 0;}
//		else if(M<=cnt) cout<<3<<'\n';
		else if(M==cnt){cout<<n-1<<'\n';return 0;}
		else if(M>cnt){cout<<n<<'\n';return 0;}
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(ll i=1;i<=n;i++) ans[i]=1;
	
	for(ll i=1;i<=n;i++){
		ll m=M;
//		cout<<a[i]<<"----\n";//
		for(ll j=i+1;j<=n;j++){
//			cout<<a[j]<<' '<<m<<' ';//
			if((a[i]-a[j])<=m&&m>0){
//				cout<<1<<' ';//
				ans[i]++;
				m-=(a[i]-a[j]);
//				cout<<m<<'\n';//
			}else break;
		}
//		cout<<'\n';
	}
	
	ll AFO=1;
	for(ll i=1;i<=n;i++){
		AFO=max(AFO,ans[i]);
	}
	
	cout<<AFO<<'\n';
	
	return 0;
}

/*
5 5
6 7 9 1 6
*/