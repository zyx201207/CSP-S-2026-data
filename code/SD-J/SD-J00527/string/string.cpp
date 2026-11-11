#include<bits/stdc++.h>
using namespace std;
long long a,o,l=0;
char b[100000000];
char y[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	long long c;
	char d;
	for(int i=0;i<a;i++){
		cin>>c>>d;
		for(int j=l;j<(l+c);j++){
			b[j]=d;
		}
		l=l+c;
	}
	
	for(int i=0;i<l;i++){
		y[i]=b[l-i-1];
	}
	long long v=0;
	for(int i=0;i<l;i++){
		if(y[i]!=b[i]){
			v=v+1;
			b[i]=y[i];
			for(int i=0;i<l;i++){
				y[i]=b[l-i-1];
			}
		}
	}
	cout<<v;
	return 0;
}
