#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,t,k=0,cnt=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		char c;
		cin>>t>>c;
		for(ll i=0;i<t;i++){
			s.push_back(c);
			k++;
		}
	}
	t=ceil(k/2);
	string temp1=s.substr(t,n-1);
	string temp2=s.substr(0,t-1);
	if(temp1==temp2){
		cout<<0<<endl;
		return 0;
	}
	for(size_t i=0;i<s.size()/2;i++){
		if(temp1[i]!=temp2[i]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
