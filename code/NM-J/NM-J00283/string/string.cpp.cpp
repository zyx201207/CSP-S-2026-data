#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("string","w",stdin);
	freopen("string","r",stdout);
	long long n;
	cin>>n;
	string z="";
	for(long long i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			z=z+b;
		}
	}
	long long f=z.size()/2;
	long long cnt=0;
	for(long long i=0,j=z.size()-1;i<z.size(),j>=0;i++,j--){
		if(z[i]!=z[j]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
