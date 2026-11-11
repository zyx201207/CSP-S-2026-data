#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,g=1,cnt=0;
	string a;
	char b;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>b;
		for(int j=g;j<=k;j++){
			a+=b;
		} 
		g=k;
	} 
	
	for(int i=1,j=a.size()-1;i<j,j>i;i++,j--){
		if(j!=i){
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
