#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N];
string b;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n<=1){
		cout<<"0";
		return 0;	
	} 
	if(n==2){
		if(a[1]>a[2]&&b[1]!=b[2]) cout<<a[2];
		else if(a[1]<a[2]&&b[1]!=b[2]) cout<<a[1];
		else cout<<"0";
	}
	return 0;
}
