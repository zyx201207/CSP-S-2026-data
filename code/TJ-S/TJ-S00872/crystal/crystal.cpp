#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
inline void solve1(){
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll maxn=0;
	for(int i=1;i<=n;i++){
		ll sum=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			cnt++;
			if(sum>=m){
				if(sum>m){
					cnt--;
					break;
				}
			}
		}maxn=max(maxn,cnt);
	}cout<<maxn+1;
	return ;
}
inline void solve2(){
	ll a,b;
	cin>>a>>b;
	ll c=abs(a-b),cnt=0,idx=1;
	while(1){
		if(m<c)break;
		m-=c*idx;
		cnt++;
		idx++;
	}cout<<cnt;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=5000){
		solve1();
	}else solve2();
	return 0;
}
