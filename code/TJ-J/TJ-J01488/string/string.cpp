#include<bits/stdc++.h>
using namespace std;
string a[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=-1;
	cin>>n;
	while(n--){
		long long x;
		char y;
		cin>>x>>y;
		for(long long i=1;i<=x;i++){
			a[++ans]=y;
		}
	}
	long long x=ans;
	ans=0;
	for(long long i=0;i<=x/2;i++){
		if(a[i]!=a[x-i]){ 
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
