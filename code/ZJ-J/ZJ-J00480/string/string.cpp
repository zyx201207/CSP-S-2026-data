#include<bits/stdc++.h>
using namespace std;
const long long N=1e8+10;
long long n,ans;
long long a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long last=1;
	int flag=1;
	for(long long i=1;i<=n;i++){
		long long b;
		char f;
		cin>>b;
		if(b!=1)flag=0;
		cin>>f;
		for(int j=last;j<last+b;j++){
			a[j]=f-'a'+1;
		}
		last+=b;
	}
	if(flag){
		cout<<n/2;
	}
	last-=1;
	for(long long i=1;i<=last/2;i++){
		if(a[i]!=a[last-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
