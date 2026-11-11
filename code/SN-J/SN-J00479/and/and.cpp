#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long maxn=0;
long long w[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	long long zzz=0;
	for(long long i=0;i<a;i++){
		cin>>w[i];
	}	
	for(long long i=1;i<a;i++){
		if(w[i-1]>w[i]){
			zzz=w[i-1];
			w[i-1]=w[i];
			w[i]=zzz;
		}
	}
	cout<<w[b];
	return 0;
}
