#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],flag,ans,dcsls[500010],dcsls_[500010];
int flag_;
int zcz;
int cha[25100000];
int da;
int ccout;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=1;
		}
		if(a[i]%a[1]!=0){
			flag_=1;
		}
		zcz+=a[n]-a[i];
	}
	if(m>=zcz){
		cout<<n;
		return 0;
	}
	//ÌØA 
	if(flag==0){
		for(int i=1;i<=n;i++){
			ans+=n-i;
			dcsls[i]=dcsls[i-1]+i;
			if(dcsls[i]==m){
				cout<<i+1;
				return 0;
			}
			if(dcsls[i]>m){
				cout<<i;
				return 0;
			}
		}
		if(m>ans){
			cout<<n;
			return 0;
		}
	}
	//ÌØB
	if(flag_==0){
		for(int i=1;i<=n;i++){
			dcsls_[i]=dcsls_[i-1]+i*a[1];
			if(dcsls_[i]==m){
				cout<<i+1;
				return 0;
			}
			if(dcsls_[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	return 0;
}
/*

Oct31==Dec25?

*/
