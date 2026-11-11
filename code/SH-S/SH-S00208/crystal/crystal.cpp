#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(a,1000000005,sizeof(a));
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=-1,sum=0,cnt=0,zuo=1;
	for(int i=2;i<=n;i++){
		sum+=(++cnt)*(a[i]-a[i-1]);
		if(sum>m){
			ans=max(ans,cnt);
			cnt--;
			sum-=a[i]-a[zuo];
			zuo++;
		}
	}
	cout<<ans;
	return 0;
} 
