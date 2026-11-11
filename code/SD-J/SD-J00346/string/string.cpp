#include <bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl;
using namespace std;
typedef long long ll;
const int N=1;
//---SD-J00346---//
string s="";
ll cntqp,cnthp=0;//听说Linux环境cnt1会CE,就这样改了 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string.log","w",stderr);
	int n;
	cin>>n;
	while(n--){
		ll a;
		char c;
		cin>>a>>c;
		while(a--) s+=c;
	}
	ll l=s.size();
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i]){
			cntqp++;
		}
	}
	for(int i=l-1;i>=l/2;i--){
		if(s[i]!=s[l-1-i]){
			cnthp++;
		}
	}
	cout<<min(cntqp,cnthp);
	return 0;
}
//别RE QwQ Luogu 1861690
//rp+=INF
