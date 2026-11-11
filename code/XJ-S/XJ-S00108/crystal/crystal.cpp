#include <bits/stdc++.h>
using namespace std;
const long long maxn=1e8+5;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long num=a[2]-a[1];
	long long k=0,ans=0;
	for(long long i=1;i<=n;i++){
		if(k!=m){
			k+=num;
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
