#include<bits/stdc++.h>
using namespace std;
long long a1[100000005]={};
long long a2[100000005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	long long a;
	cin>>a;
	long long j=0,o=0;
	for(long long i=0;i<a;i++){
		int l;
		char m;
		cin>>l>>m;
		o=l+o;
		for(;j<o;j++){
			a1[j]=int(m)-96;
			a2[j]=a1[j];
		}
	}
	long long k=o/2;
	reverse(a2,a2+o);
	long long ans=0;
	for(long long i=0;i<=k;i++){
		if(a2[i]!=a1[i]){
			ans++;
		}
	}
	cout<<ans;
}
