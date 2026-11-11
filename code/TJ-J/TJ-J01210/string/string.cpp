#include<bits/stdc++.h>
using namespace std;

long long x,n,l,sum,h;
char c;
string s,ss,t,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int k=0;k<x;k++){
			s+=c;
		}
		h+=x;
	}
	
	ss=s;
	reverse(ss.begin(),ss.end());
	if(ss==s) cout<<0;
	else{
		l=s.size()/2;
		if(l%2==1){
			t=s.substr(0,l);
			r=s.substr(l+1); 
		}
		else{
			t=s.substr(0,l);
			r=s.substr(l); 
		}
		reverse(r.begin(),r.end());
		for(int j=0;j<l;j++){
			if(t[j]!=r[j]) sum++;
		}
		cout<<sum;
	}
	return 0;
}
