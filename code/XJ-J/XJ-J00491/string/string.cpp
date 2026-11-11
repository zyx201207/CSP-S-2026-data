#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num;
char c[200005],s;
int mian(){
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	} for(int i=;i*2<n;i++){
		if(s[i]!=s[n-i]){
			num+=1;
		}
	} cout<<num;
	return 0;
}