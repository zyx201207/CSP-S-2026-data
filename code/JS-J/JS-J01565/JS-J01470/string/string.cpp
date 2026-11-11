#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s1=0,k=0;
	cin>>n;
	int a[n+1];
	char b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s1+=a[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=1;i<=s1;i++){
		if(s[i-1]!=s[s1-i]){
			k++;
		}
	}
	cout<<k/2;
	return 0;
}
