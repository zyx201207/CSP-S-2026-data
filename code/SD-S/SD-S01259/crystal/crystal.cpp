#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	LL m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;j<=n;){
//		if(j)
		if((j-i+1)*1ll*a[j]-b[j]+b[i-1]<=m)j++;
		else i++;
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
}
