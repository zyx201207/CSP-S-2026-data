#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m;
ll a[N];
ll q[N];
string s;
string f="9223372036854775800";
ll cmp(){
	if(s.size()>f.size())return 1;
	if(s.size()<f.size())return 0;
	for(int i=0;i<f.size();i++){
		if(s[i]>f[i])return 1;
	} 
	return 0;
} 
//LLONG_MAX=9223372036854775807
ll solve(){
	sort(a+1,a+1+n);
	ll ft=n,bk=n;
	ll cnt=0;
	ll ans=0;
	for(int i=n-1;i>=1;i--){
		ans=max(ans,bk-ft+1);
		--ft;
		cnt+=a[bk]-a[i];
		if(cnt>m){
			while(cnt>m&&ft!=bk){
				cnt-=(a[bk]-a[bk-1])*(bk-ft);
				bk--;
			}
		}
//		cout<<ft<<" "<<bk<<" "<<cnt<<endl;
	}
	ans=max(ans,bk-ft+1);
	cout<<ans;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(cmp()==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		m*=10;
		m+=s[i]-'0';
	}
	solve();
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
3 9223372036854775808
1 2 3
3 5000000000000000000
1 2 3
3 100000000000000000000
1 2 3
*/
