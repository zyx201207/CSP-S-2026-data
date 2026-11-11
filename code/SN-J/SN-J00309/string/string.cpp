#include<bits/stdc++.h>
using namespace std;
long long cnt,ii;
int n;
long long a[5000000];
char s[5000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>s[i];	
	}
	for(int i = 0;i<(n/2);i++){
		if(s[i] != s[n-i-1]){
			cnt+=a[i];
		}
	}
	/*for(int i = 1;i<=n;i++){
		for(int j = 1;j<=a[i];j++){
			cout<<ii<<" "; 
			s[ii] = c[i];
			ii++;
		}	
	}
	for(int i = 0;i<(ii/2);i++){
		if(s[i] != s[ii-i-1])
			cnt++;
	}*/
	cout<<cnt;
	return 0;
}
