#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf=9223372036854775807;

int n,m,a[N],ans,ssuumm=inf,ok=1,cnt1,cnt2,cnt3,cnt0,tot=inf;//ok 是否a[i]<4     cnt[i]  2^i的个数； 
void solve(){
	cout<<0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ssuumm&=a[i];
		if(a[i]>=4) ok=0;
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
		if(a[i]==2) cnt2++;
		if(a[i]==3) cnt3++;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		for(int i=0;i<=(1<<n)-1;i++){
			int cnt=0,sum=inf;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					cnt++;
					sum&=a[j+1];
				}
			}
			if(cnt!=m) continue;
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			cout<<a[n];
			return 0;
		}else if(m==n){
			cout<<ssuumm;
			return 0;
		}else if(m==2){
			int num=inf;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int num=inf;
					num&=a[i];
					num&=a[j];
					ans=max(ans,num);
				}
			}
			cout<<ans;
			return 0;
		}else{
			goto g;
		}
	}
	g:
	if(ok){
		if(cnt3>=m){
			cout<<3;
			return 0;
		}else{
			if(cnt2>=m-cnt3){
				cout<<2;
				return 0;
			}
			else{
				if(cnt1>=m-cnt2-cnt3) {
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	else if(m==n-1){
		int aannss=0;
		for(int i=1;i<=n;i++){
			int sum=inf;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum&=a[j];
			}
			aannss=max(aannss,sum);
		}
		cout<<aannss;
		return 0;
	}else{
		solve();
	}
	return 0;
}
