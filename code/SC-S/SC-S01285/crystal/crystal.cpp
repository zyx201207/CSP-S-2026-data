#include<bits/stdc++.h>
/*
pts 100
time 15:07
up_date \
*/
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
const int N = 5e5 + 1000 ;
ll n,m;
ll ans;
ll cnt[N];
ll nt[N];
ll a[N];
ll sum;
int main (){
//	freopen("crystal3.in","r",stdin);
//	freopen("crystal.ans","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	cnt[i]=a[i]-a[i-1];
	ll l=1;
	sum=1;
	for(ll i=1;i<=n;i++){
		ans=ans+(a[i]-a[i-1])*(i-l);
		while(l<i&&ans>m){
			//cout<<ans<<"<->";
			ans-=a[i]-a[l];
			l++;
		}
		//cout<<l<<" "<<i<<" "<<ans<<"\n";
		sum=max(sum,i-l+1);
	}
	sum=max(sum,n-l+1);
	cout<<sum;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/