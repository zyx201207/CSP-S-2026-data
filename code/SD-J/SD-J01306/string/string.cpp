#include<bits/stdc++.h>
using namespace std;
long long n=0,a[200001],x=0,f=0;long long si,sa=0;
string c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	si=n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			if(sa==a[si-1]){
			si--;
			sa=0;
			}
			if(c[i]!=c[si-1])x++;
			sa++;
	    }
	}
	cout<<x/2;
	return 0;
} 

