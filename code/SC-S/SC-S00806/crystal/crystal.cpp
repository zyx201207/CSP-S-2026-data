#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],b[500002],cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<i;j++){
			cnt+=a[i]-a[j];
		}
		if(cnt<=m) ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}