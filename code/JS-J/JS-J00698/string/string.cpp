#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		scanf("%lld",&a);
		scanf("%hhd",&c);
		string t(a,c);
		s+=t;
		//cout<<"ok"<<endl;
	}
	s=' '+s;
	cout<<s.size()<<endl;
	ll len=s.size()-1;
	for(ll i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i]){
			cnt++;
		}
		
	}
	cout<<cnt<<endl;
	//ll l=0,r=a/2;
	//while(l<=r){
	//	ll mid=l+r>>1;
	//	if(check())
	//}
	return 0;
}
