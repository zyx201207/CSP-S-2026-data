#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,l,time=0;
	cin>>n;
	long long s[n];
	char c[n];
	char a[1000];
	char b[1000];
	for(int i=0;i<n;i++){
		cin>>s[i]>>c[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i];j++){
			a[j]=c[i];
		}
	}
	for(int i=0;i<n;i++){
		l=l+s[i];
	}
	for(int i=l;i+0;i++){
		b[i]=a[l-i];
	}
	for(int i=0;i<l;i++){
		if(b[i]!=a[i]){
			time+1;
		}
	}
	time=time/2;
	cout<<time;
	return 0;
}
