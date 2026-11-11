#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a=" ";
ll n;
ll len=0;
ll x;
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	
	cin >> n;
	
	for(ll i=0;i<n;i++){
		
		char c;
		cin >> x >> c;
		len+=x;
		while(x--)a+=c;
	}
	
	for(ll i=1;i<=len/2;i++){
		if(a[i]!=a[len-i+1])ans++;
	}
	cout << ans << endl;
	return 0;
}
