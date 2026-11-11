#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,q=0,cnt=0;
	cin>>n;
	string c;
	for(int i=1;i<=n;i++){
		long long k;
		char s;
		cin>>k>>s;
		for(int j=q;j<k+q;j++){
			c[j]=s;
		}
		q+=k;
	}
	for(int i=0;i<q/2;i++){
		if(c[i]!=c[q-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}

