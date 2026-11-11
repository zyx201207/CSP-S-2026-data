#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	string s;
	char b;
	ll a;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b;
		for(ll k=0;k<a;k++){
			s+=b;
		}
	}
	ll sum=0;
	ll si=s.size();
	ll j=si-1;
	if(si%2==0){
		for(ll i=0;i<(si+1)/2;i++){
			if(s[i]==s[j])j--;
			else{
				j--;
				sum++;
			}
		}
	}else{
		for(ll i=0;i<(si-1)/2;i++){
			if(s[i]==s[j])j--;
			else{
				j--;
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
