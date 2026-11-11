#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n;
string s=" ";
ll l;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
		l+=a;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
