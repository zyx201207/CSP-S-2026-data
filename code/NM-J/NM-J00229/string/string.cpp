#include<bits/stdc++.h>
using namespace std;
//bool isPrime(long long n){
//	for(int i=2;i*i<=n;i++){
//		if(n%i==0){
//			return false;
//		}
//	}
//	return true;
//}
long long gcd(long long x,long long y){
	long long a=x,b=y; 
	if(a==b){
		return a;
	}
	if(a==1||b==1){
		return 1;
	}
	while(true){
		if(a>b){
			a-=b;
			if(x%a==0&&y%a==0){
				return a;
			}
		}else if(b>a){
			b-=a;
			if(x%b==0&&y%b==0){
				return b;
			}
		}	
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
 	int n;
 	string s="",b="";
 	cin>>n;
 //	cout<<1;
 	int gcdn = 0;
 	int slp[200005][2] = {};
 	for(unsigned long long i=0;i<n;i++){
 		long long t;
 		char a;
 		cin>>t>>a;
 		slp[i][0] = a;
 		slp[i][1] = t;
 		if(i==0){
 			gcdn =  t;	
		}else{
			gcdn = gcd(gcdn,t);
		}
	}
//	cout<<2;
//	printf("gcdn %i   n %i",gcdn,n); 
	for(long long i=0;i<n;i++){
		for(long long j=0;j< slp[i][1]/gcdn;j++){
			s+=slp[i][0]; 
		}
	}
//	cout<<3;
	long long ans =0; 
	if(s.length()%2==0){
		for(long long i=s.length()-1;i>s.length()/2-1;i--){
			b+=s[i];
		}
	}else{
		for(long long i=s.length()-1;i>s.length()/2;i--){
			b+=s[i];
		}
	}
//	cout<<4<<endl;
	for(long long i=0;i<b.length();i++){
		if(s[i]!=b[i]){
			ans++; 
		}
	}
	cout<<ans*gcdn;
	return 0;
} 
