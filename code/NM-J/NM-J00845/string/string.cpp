#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	string s[n+5];
	for(int i = 0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	long long b = 0;
	for(int i = 0;i<n;i++){
		b+=a[i];
	}
	int d = n-1;
	long long m = 1;
	for(int i = 0;i<b/2;i++){
		if(s[i]!=s[d]){
			m+=1; 
		}
		d-=1;
	}
	cout<<m;
	return 0;
}
