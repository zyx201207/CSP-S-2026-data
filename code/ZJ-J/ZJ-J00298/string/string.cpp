#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5];
	long long l=0,m=0;
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
}