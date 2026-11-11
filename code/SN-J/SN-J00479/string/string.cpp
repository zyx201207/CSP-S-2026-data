#include<bits/stdc++.h>
using namespace std;
char h[1000000000]={};
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,change=0,mzl=0;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b>>c;
		for(long long j=0;j<b;j++){
			h[j+i]=c;
			mzl++;
		}
	}
	
	for(long long i=0;i<mzl/2;i++){
		if(h[i]!=h[mzl-i-1]) change++;
	}

	cout<<change;
	return 0;
}
