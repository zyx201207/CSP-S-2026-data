#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
ll n;
const ll N=2e5+10;
ll a[N],pre[27][N];
char c[N];//a:sum_pre总数前缀,c:i-th char第i的字符,pre 'a'+j的字符前缀和
//map<ll,char>mp;
ll sum=0;
ll ans=0;
ll dui(ll x){
	return sum+1-x;
}
ll same(ll l,ll r,char cc){
	l=dui(l),r=dui(r);
	ll res=0;
	swap(l,r);
	ll left=lower_bound(a+1,a+1+n,l)-a,right=lower_bound(a+1,a+1+n,r)-a;
//	cout<<left<<' '<<right<<'\n';
	ll u=cc-'a';
	//mid part中间部分
	if(left+1<=right-1){
		res+=pre[u][right-1]-pre[u][left];
	}
	//edge part
	if(left==right&&c[left]-'a'==u){
		res+=r-l+1;
	}
	else{
		if(left==right){
			return res;
		}
		if(c[left]-'a'==u){
			res+=a[left]-l+1;
		}
		if(c[right]-'a'==u){
			res+=r-a[right-1];
		}
	}
	return res;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		mp[sum+1]=a[i];
		sum+=a[i];
		
		for(ll j=0;j<=25;j++){
			if('a'+j==c[i]){
				pre[j][i]=pre[j][i-1]+a[i];
			}
			else pre[j][i]=pre[j][i-1];
		}
		a[i]=sum;
	}
	ll midd=(lower_bound(a+1,a+1+n,sum/2+1)-a);
ll l=sum/2+1,r=a[midd];
	ans+=r-l+1-same(l,r,c[midd]);
//	cout<<dui(r)<<' '<<dui(l)<<' '<<same(l,r,c[midd])<<'\n';
	for(ll i=midd+1;i<=n;i++){
		ll le=a[i-1]+1,ri=a[i];
		ans+=ri-le+1-same(le,ri,c[i]);
//		cout<<r-l+1-same(l,r,c[i])<<'\n';
	}
	cout<<ans;
}
/*
Trick||Treat!
5
3 b
2 a
2 b
4 a
2 c
*/