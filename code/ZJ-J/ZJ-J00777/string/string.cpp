#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long a[n+10];
	char c[n+10];
	for(long long i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j = 1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long len=s.length();
	if(n<=1){
		cout<<0;
	}
	else if(n<=2){
		if(c[1]==c[2]){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]);
		}
	}
	else{
		long long mid =len/2,l=0,r=len-1;
		for(long long k=0;k<=mid&&l<r;k++){
			if(s[l]!=s[r]){
				ans++;
			}
			l++,r--;
		}
		cout<<ans;
	}
	return 0;
}

