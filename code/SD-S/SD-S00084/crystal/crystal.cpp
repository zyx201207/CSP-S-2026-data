#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) x&(-x)
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=1e6+10;//×¢ÒâÐÞ¸Ä

ll n,m;
ll a[N],b[N],c[N];


bool check(int mid,int x){
	ll sum1=c[x];
	//cout<<sum1<<' ';
	sum1-=c[mid];
//	cout<<sum1<<' '; 
	sum1-=(mid)*(a[x]-a[mid]);
//	cout<<sum1<<endl;
	if(sum1<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fst
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i]*i;
	}
	//cout<<check(3,7);
	ll maxx=0;
	for(int i=2;i<=n;i++){
		ll l=1,r=i,ans=5e5+1;
		while(l<=r){
			ll mid=(l+r+1)>>1;
			if(check(mid,i)){
			//	cout<<i<<' '<<mid<<endl;
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
	return 0;
}
/*
7 4
-9 -5 0 3 4 6 7

*/




