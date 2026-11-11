#include<bits/stdc++.h>
using namespace std;
string sum="";
long long n,cg=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n]={};
	char b[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++) sum+=b[i];
	}
	for(int i=0;i<n/2;i++){
		if(b[i]!=b[n-1-i]){
			cg++;
			break;
		}
	}
	if(cg!=0) cout<<n/2;
	else cout<<cg;
	return 0; 
}
