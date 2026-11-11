#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> a;
vector<char> b;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	bool f=1;
	char l;
	for(ll i=1;i<=n;i++){
		ll t1;
		char t2;
		cin>>t1>>t2;
		a.push_back(t1);
		b.push_back(t2);
		if(i!=1){
			if(t2!=l){
				f=0;
			}
		}
		l=t2;
	}
	if(f){
		cout<<"0";
		return 0;
	}
	/*for(ll i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(ll i=0;i<b.size();i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	for(ll i=0;i<a.size();i++){
		for(ll j=1;j<=a[i];j++){
			str+=b[i];
		}
	}
	//cout<<str;
	ll sum=0;
	string str1=str;
	reverse(str1.begin(),str1.end());
	if(str.length()%2==1){
		for(ll i=str.length()/2+1;i<str.length();i++){
			if(str[i]!=str1[i]){
				sum++;
			}
		}
	}
	else{
		for(ll i=str.length()/2;i<str.length();i++){
			if(str[i]!=str1[i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
