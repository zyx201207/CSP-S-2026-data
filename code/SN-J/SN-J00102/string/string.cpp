#include<bits/stdc++.h>
using namespace std;
string s[200000];
string S;
string hw;
long long ans;
int a[200000];
long long L;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<a[i];j++){
			S+=s[i];
			L++;
		}
	} 
	for(long long i=0;i<L;i++){
		hw+=S[L-1-i];
	}
	for(long long i=0;i<L;i++){
		if(hw[i]!=S[i]){
			hw[i]=S[i];
			S[L-1-i]=S[i];
			ans++;
		}
	}
	cout<<ans;
	return 0; 
} 
