#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL n,m,ans;
LL a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(LL i=n;i>=1;i--){
		for(LL j=i;j>=1;j--){
			ans+=i-j;
		}
		if(ans<=m){
			cout<<i;
			return 0;
		}else{
			ans=0;
		}
	}
	return 0;
} 
