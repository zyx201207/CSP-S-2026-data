#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long ll;
ll n,a;
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	ll sum=0;
	string s;
	for(ll i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(ll j=0;j<a;j++){
			s+=c;
		}
		sum+=a;
	}
	ll cnt=0;
	for(ll i=0;i<sum;i++){
		if(i>=(sum-i-1)){
			break;
		}
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
