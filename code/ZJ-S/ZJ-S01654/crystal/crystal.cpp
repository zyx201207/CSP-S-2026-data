#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],ans=0;
void check(int x){
	long long mnow=m;
	int sum=0,now=x;
	while(mnow>=a[x]-a[now] && now>=1){
		mnow-=a[x]-a[now];
		now--;sum++;
	}
	ans=max(ans,sum);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		check(i);
	}cout<<ans;
	return 0;
}

