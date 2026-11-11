#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		while(x--)s+=y;
	}
	string a=s.substr(0,s.size()/2);
	string b=s.substr(s.size()/2,s.size()/2);
	reverse(b.begin(),b.end());
	ll sum=0;
	for(int i=0;i<a.size();i++)if(a[i]!=b[i])sum++;
	cout<<sum;
	return 0;
}
