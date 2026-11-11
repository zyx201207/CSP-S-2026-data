#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n;
	cin>>n;
	long long k=0;
	string sum="0";
	for(long long i=1;i<=n;i++){
		char b;
		long long a;
		cin>>a>>b;
		k+=a;
		while(a--){
			sum+=b;
		}
	}
	long long ans=0;
	for(long long i=1;i<=(k+1)/2;i++){
		long long ne=k+1-i;
		if(sum[i]!=sum[ne]){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
