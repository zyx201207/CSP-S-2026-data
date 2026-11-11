#include<bits/stdc++.h>
using namespace std;
long long n,x,a[100000000],t,b[100000000];
char c[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=a[i];j++){
			b[j]=c[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=b[x]){
			t++;
		}
		x--;
	}
	cout<<t;
	return 0;
} 
