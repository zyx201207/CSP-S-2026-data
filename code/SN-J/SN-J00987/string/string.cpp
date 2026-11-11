#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n , cnt=0;
	cin>>n;
	int a[n];
	char c[n] , s[n];
	for(int i = 0;i<n;i++){
		cin>>a[i]>>c[i];
		s[i] = c[i]*a[i];
	}
	for(int k = 0;k<n;++k){
		if(!(c[k] == c[k+1])){
			break;
		}
		if(k==n-2&&c[k]==c[k+1]){
		    cout<<0;
		    return 0;
	    }
	}
	for(int i = 0;i<n;i++){
		if(!(s[i]==s[n-i-1])){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
