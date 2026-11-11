#include<bits/stdc++.h>
using namespace std;
long long m[200001];
char a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0,l=0,b=0,k=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m[i]>>a[i];
		l+=m[i];
	}
	long long w=l+1,c=n+1;
	for(long long i=1;i<=l/2;i++){
		if(i>k){
			b++;
			k+=m[b];
		}
		if(l-i+1<w){
			c--;
			w-=m[c];
		}
		if(a[b]!=a[c]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
