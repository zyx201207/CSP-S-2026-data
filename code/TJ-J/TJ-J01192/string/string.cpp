#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	string a="0",b;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>b;
		for(long long j=0;j<m;j++){
			a+=b;
		}
	}
	m=0;
	for(long long i=1;i<=(a.size()-1)/2;i++){
		if(a[i]!=a[a.size()-i]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
