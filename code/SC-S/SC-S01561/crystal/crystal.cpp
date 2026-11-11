#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],c[500010],sam[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		c[i]=a[i+1]-a[i];
		sam[i]=sam[i-1]+c[i];
	}
	int cnt=1,ans=0,i=1,j=1,cntl=0;
	while((j<=n&&i<=n)&&(i<=j)){
		if(ans<=m){
			ans=ans+c[j]*(j-i+1);
			j++;
			cnt++;
		}
		else{
			cntl=max(cntl,cnt-1);
			i++;
			ans-=sam[j]-sam[i-1];
			cnt--;
		}
	}
	cout<<cntl;
	return 0;
}