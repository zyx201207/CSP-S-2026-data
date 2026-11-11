#include <bits/stdc++.h>
using namespace std;
string s;
long long x;
long long ans=0;
long long hui(){
	bool t=1;
	if(s.size()%2==0){
		x=s.size();
	}else{
		x=s.size()-1;
	}
	x=x/2;
	if(s.size()%2==0){
		for
		(long long i=0;i<=x;i++){
			if(s[i]!=s[2*x-i-1]){
				t=0;
				ans++;
		}
	}
	}else{
		for(long long i=0;i<x;i++){
			if(s[i]!=s[2*x-i]){
				t=0;
				ans++;
			}
		}
	}
	
	return t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	long long v=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		string c;
		cin>>a;
		cin>>c;
		a+=v;
		for(int j=v;j<a;j++){
			s+=c;
		}
		v+=a;
	}
	if(hui()){
		cout<<0;
	}else{
		cout<<ans;
	}
	
	return 0;
}
