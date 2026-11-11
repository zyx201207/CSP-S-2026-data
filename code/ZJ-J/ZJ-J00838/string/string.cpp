#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200010];
	char b[200010],d[200100];
	long long n,t=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long k;
		char c;
		cin>>k>>c;
		if(k>=1e7){
			cout<<3*k;
		}
		for(int i=t+1;i<=t+k;i++){
			a[i]=c;	
		}
		t+=k;
	}
	for(int i=1;i<=t/2;i++){
		b[i]=a[i];
	}
	if(t%2==0){
		int o=1;
		for(int i=t;i>=t/2+1;i--){
			d[o]=a[i];
			o++;
		}
	}else{
		int o=1;
		for(int i=t;i>=t/2+2;i--){
			d[o]=a[i];
			o++;
		}
	}
	for(int i=1;i<=t/2;i++){
		if(b[i]!=d[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}