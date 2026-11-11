#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long m,n,a[maxn],sum[maxn],ans;
bool t=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
		if(sum[i]+m<a[i]*i){
			ans=i-1;
			t=1;
			break;
		}
	}
	if(t)cout<<ans;
	else cout<<n;
	return 0;
}
