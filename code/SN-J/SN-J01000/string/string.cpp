#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string z="";
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long k=1;k<=x;k++){
			z+=y;
		}
	}
	long long cnt=0;
	long long len=z.size();
	long long kx=0;
	for(long long j=0;j<len/2;j++){
		if(z[j]!=z[len-1-kx]){
			cnt++;
		}
		kx++;
	}
	cout<<cnt;
	
	
	return 0;
}
