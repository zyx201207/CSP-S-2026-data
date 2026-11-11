#include <bits/stdc++.h>
using namespace std;
long long k[200005];
char b[200005];
string f[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m,n=0,p=0;
	cin>>m;
	for(long long i=1;i<=m;i++){
		cin>>k[i]>>b[i];
	}
	for(long long i=1;i<=m;i++){
		while(k[i]!=0){
			n++;
			f[n]+=b[i];
			k[i]--;
		}
	}
	for(long long l=1;l<=n/2;l++){
		if(f[l]!=f[n-l]){
			p++;
		}
	}
	cout<<p;
	return 0;
}
