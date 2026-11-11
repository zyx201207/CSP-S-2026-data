/*
abba

*/
#include<bits/stdc++.h>
using namespace std;
long long a[100000+100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[10000+100];
	string s,s1,s2;
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}//else if(){
////		
////	}
	int m=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i+1]){
			cout<<0;
			return 0;
		}
		s+=c[i];
	}
//	cout<<s;
//	for(int i=1;i<=n;i++){
//		
//	}
	for(int i=1;i<=m;i++){
		
		for(int j=m;j<=n;j++){
			
		} 
	}
	return 0;
} 
