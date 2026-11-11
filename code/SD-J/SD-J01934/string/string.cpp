#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,aa=0,a=0,b=0,c=0;
	char cc;
	char S[100];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>cc;
		for(int j=1;j<=aa;j++){
			S[i]=cc;
		}	
	}
	a=1;
	b=n;
	for(int i=1;i<=n/2;i++){
		if(S[a]!=S[b]){
			c=c+1;
		}
		a+=1;
		b+=1;
	}
	cout<<c;
	return 0;
}
