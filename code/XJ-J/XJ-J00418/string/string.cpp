#include<bits/stdc++.h>
using namespace std;
string c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0;
	string b;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long i=0;i<a;i++){
			c=c+b;
		}
	}
	for(long long i=c.size()-1;i>=0;i--){
		d=d+c[i];
	}
	if(d==c){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<c.size();i++){
		if(c[i]!=d[i]) cnt++; 
	}

	cout<<cnt;
	return 0;
}
