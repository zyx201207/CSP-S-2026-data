#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m;
ll a[N];//原数组 
ll pw2[35];
string er[N];//二进制情况下的数
ll ma=0,ma_n=0;
struct c{
	ll to,total;
}cnt[N];
bool cmp(c x,c y){
	if(x.total!=y.total){
		return x.total>y.total;
	}else{
		return x.to>y.to;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pw2[1]=1;
	for(int i=2;i<=30;i++){
		pw2[i]=pw2[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll cnt1=0;
		ll z=a[i];
		for(int j=30;j>=1;j--){
			if(pw2[j]>z){
				er[i]+='0';
			}else{
				er[i]+='1';
				cnt1++;
				z-=pw2[j];
				if(z==0){
					break;
				}
			}
		}
		if(cnt1>ma){
			ma=cnt1;		
			ma_n=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==ma_n){
			continue;
		}
		ll t=0;
		cnt[i].to=a[i];
		for(int j=1;j<=30;j++){
			if(er[ma][j]==1&&er[i][j]==1){
				t++;
			}
		}
		cnt[i].total=t;
	}
	sort(cnt+1,cnt+n+1,cmp);
	ll ans=ma_n;
	for(int i=2;i<=m;i++){
		ll q=cnt[i].to;
		ans=(ans&q);
	}
	cout<<ans;
	return 0;
}
