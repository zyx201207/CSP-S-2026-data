#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		if(a[i]-a[1]<=a[1]){
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
