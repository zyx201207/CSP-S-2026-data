#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T;
ll a[N];
ll n,d;
bool check(ll l,ll r){
	if(abs(a[r]-a[l])<=d&&abs(r-l)==1){
		return true;
	}
	int flag=0;
	if(abs(a[r]-a[l])>d){
		for(int i=l;i<=r;i++){
			if(flag>1)return false;
			int cntl=0,cntr=0;
			for(int j=i+1;j<=i+3;j++){
				if(abs(a[j]-a[i])<=d)cntl++;
				if(abs(a[i+4]-a[j])<=d)cntr++;
			}
			if(cntl==3&&cntr==3)return false;
			if(cntl==2&&cntr==2)flag+=1;
		}
	}
	if(flag==1)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ll cnt=0;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=1;
		while(r<=n){
			if(check(l,r))cnt++;
			if(abs(r-l)>d)l++;
			else r++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 