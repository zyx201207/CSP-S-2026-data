#include<bits/stdc++.h>
using namespace std;
int s[1000010];
int x[1000010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s[i]=a;
		int c=0,b=0;
		while(a!=0){
			b=b*10+a%2;
			a/=2;
		}
		while(b!=0){
			c=c*10+b%10;
			b/=10;
		}
		x[i]=c;
	}
	return 0;
}
