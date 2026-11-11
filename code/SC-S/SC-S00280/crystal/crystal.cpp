#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cnt=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	int a[n+10],b[n+10];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		b[i]=abs(a[i]-a[i-1]);
//	}
	for(int i=1;i<=n;i++){
		if(cnt<=m){
			cnt+=i*abs(a[i+1]-a[i]);
		}else{
			cout<<i-1;
			return 0;
		}
	}
	return 0;

}