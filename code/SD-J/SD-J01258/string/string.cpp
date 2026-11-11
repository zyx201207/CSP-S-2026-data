#include<bits/stdc++.h>
using namespace std;
long long a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0,d=0,p=0;
	string m,l;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>m[i];
		c+=a[i];
		d+=a[i-1];
		for(long long j=d;j<=c;j++){
			l[j]=m[i];
		}
	}
	for(int i=1;i<n;i++){
		if(l[i]!=l[c+1-i]){
			p++;
		}
	}
	cout<<p;
	return 0;
} 
