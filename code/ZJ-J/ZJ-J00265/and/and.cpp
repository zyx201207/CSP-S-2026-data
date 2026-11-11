#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans=1;
ll yu(ll x,ll y){
	string s,d;
	ll pp;
	while(x>=1){
		s+=char(x%2+48);
		x/=2;
	}
	while(y>=1){
		d+=char(y%2+48);
		y/=2;
	}
	for(int i=0;i<=s.size()-1;i++){
		swap(s[i],s[s.size()-i]);
	}
	for(int i=0;i<=d.size()-1;i++){
		swap(d[i],d[s.size()-i]);
	}
	for(int i=0;i<=min(s.size()-1,d.size()-1);i++){
		if(s[i]=='1'&&d[i]=='1'){
			ll o=pow(2,i);
			pp+=o;
		}
	}
	
	return pp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=n;i>=m;i--){
		ans=yu(a[i],ans);
	}
	cout<<ans;
	return 0;
} 

