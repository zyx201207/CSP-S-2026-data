#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,l,L=0,num=0;
	string w,s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>w;
		for(ll j=0;j<l;j++){
			s+=w;
		}
		L+=l;
	}
	for(ll i=0;i<L/2;i++){
		if(s[i]==s[L-1-i]){
			num++;
		}
	}
	cout<<L/2-num;	
	
	return 0;
}

