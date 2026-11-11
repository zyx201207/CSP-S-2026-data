#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[200050],base[35],ans,num[35];
string s[200050];
string solve(ll x){
	ll sta[35],pos=0;
	string str;
	while(x){
		sta[++pos]=x%2;
		x/=2;
	}
	for(int i=pos;i>=1;i--){
		str+=sta[i]+'0';
	}
	return str;
}
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	base[1]=1;
	for(int i=2;i<=30;i++){
		base[i]=base[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=solve(a[i]);
	}
	sort(s+1,s+n+1); 
	for(int i=n;i>=n-k+1;i--){
		ll len=s[i].size();
		for(int j=0;j<len;j++){
			if(s[i][j]=='1') num[len-j]++;
		}
	}
	for(int i=1;i<=30;i++){
		if(num[i]==k) ans+=base[i];
	}
	cout<<ans;
	return 0;
}

