#include<bits/stdc++.h>
using namespace std;
long long  n,a,a1;
char b;
char s[10000005];
long long  bs=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		a1+=a;
		cin>>b;
		for(int i=1;i<=a;i++){
			s[i]=b;
		}
	}
	for(int i=1,j=a1;i<=j;i++,j--){
		if(s[i]!=s[j]) bs++;
	}
	cout<<bs;
	return 0;
} 
