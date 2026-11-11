#include<bits/stdc++.h>
using namespace std;
int n,a[999],i;
char b[999];
string s;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int j=0;j<n;j++){
		if(a[i]>0) {
			s+=b[i];
			a[i]-=1;
		}
		else i-=1;
	}
	cout<<0;
	return 0;
} 
