#include<bits/stdc++.h>
using namespace std;
#define ll long long
//15:00  假了1
//16:00假了345
//求你了T1给过吧 
const ll INF=1e12+10;
const ll N=5e5+10;
ll n,m;
ll ans,qwq;
ll a[N],c[N];
void solve2(){

}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	//满分 
	//牛逼T1思想假了5遍 ,16:09 done
	cin>>n>>m;
	ll r=1e17+10;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll l=0,ans=1;
	sort(a,a+n);
	while(l<=r){
		ll mid=(l+r)/2;
//		cout<<l<<" "<<mid<<" "<<r<<endl;
		ll cnt=0;
		for(ll i=0;i<n;i++){
			if(a[i]<=mid) cnt+=mid-a[i];
			else break;
		}
		if(cnt<=m){
			ans=mid;
//			cout<<ans<<"\n";
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	} 
////	cout<<ans<<"\n"; 
	ll ln=0,kek=0;
	for(ll i=0;i<n;i++){
		if(kek+ans-a[i]>m||ans-a[i]<0) break;
		else {
			kek+=(ans-a[i]);
			ln++;
		}
	}
	cout<<ln;
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5 
1 2 4 8 9
*/
