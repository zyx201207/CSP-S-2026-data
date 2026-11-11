#include<bits/stdc++.h>
using namespace std;
long long n,a,c,d;
char b,b1[100001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		c=c+a;
		for(int j=c-a;j<c;j++){
			b1[j]=b;
		}
	}
	for(int i=0;i<=c/2;i++){
		if(b1[i]!=b1[c-i-1]){
			d++;
		}
	}
	cout<<d;
	return 0;
}
