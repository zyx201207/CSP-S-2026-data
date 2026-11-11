#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
int n;
ll a[N],sum[N];
char c[N];
ll ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//cout<<1;
	cin>>n;
	s+='1';
	for(int i=1;i<=n;i++){
		//cout<<1;
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
		sum[i]=sum[i-1]+a[i];
		//cout<<s<<'\n'; 
	}
	
	for(int i=1;i<=(sum[n]+1)/2; i++){
		if(s[i]!=s[sum[n]+1-i]) ans++;
	}
	
	//cout<<s;
	cout<<ans;
	
	return 0;
}
/*
3 2 a 2 b 1 c
*/
