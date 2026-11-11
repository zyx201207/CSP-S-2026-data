#include<bits/stdc++.h>
using namespace std;
struct String{
	long long r;
	string l;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	long long ans=0;
	long long len=0;
	string L="";
	cin>>n;
	vector<String> S(n);	
	for(int i=0;i<n;i++){
		cin>>S[i].r>>S[i].l;
		len+=S[i].r;
		for(long long j=0;j<S[i].r;j++){
			L+=S[i].l;
		}
	}
	if(len%2==0){
		for(long long i=0;i<=len/2;i++){
			if(len-i-1<=i)break;
			if(L[i]!=L[len-i-1]){
				ans++;
			}		
		}		
	}else{
		for(long long i=0;i<=len/2;i++){
			if(len-i-1<i)break;
			if(L[i]!=L[len-i-1]){
				ans++;
			}		
		}
	}
	cout<<ans;
	return 0 ;
}
