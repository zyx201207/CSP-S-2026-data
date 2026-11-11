#include<bits/stdc++.h>
using namespace std;
string s;
long long n,l,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
		l=l+a;
	}
	if(l%2!=0){
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				cnt1++;
			}
		}
		for(long long i=l/2+1;i<l;i++){
			if(s[i]!=s[l-i-1]){
				cnt2++;
			}
		}
		if(cnt1<cnt2){
			cout<<cnt1;
		}else{
			cout<<cnt2;
		}
	}else{
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				cnt1++;
			}
		}
		for(long long i=l/2;i<l;i++){
			if(s[i]!=s[l-i-1]){
				cnt2++;
			}
		}
		if(cnt1<cnt2){
			cout<<cnt1;
		}else{
			cout<<cnt2;
		}
	}
	return 0;
} 
