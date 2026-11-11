#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[100005];
bool c(long long x,long long y){
	return x>y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,c);
	for(long long i=1;i<=m;i++){
		if(i==1){
			ans=a[i];
			continue;
		}
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
