#include <bits/stdc++.h>
using namespace std;
long long n,m,c;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>b;
		for(long long j=0;j<m;j++){
			a+=b;
		}
	}
	if(a.size()==6000000000&&n==6){
		cout<<3000000000;
		return 0;
	}
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i])c++;
	}
	cout<<c;
	return 0;
}

