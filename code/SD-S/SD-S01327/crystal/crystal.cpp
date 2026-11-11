#include<iostream>
#include<algorithm>
#define int long long
#define N 500001
int n,m,a[N],sum[N],ans,yans,cnt=0; 
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]; 
	for(int i=1,j=1;i<=n&&j<=n;){
		if(cnt>=j-i+1){
			j++;
			continue;
		}
		ans=sum[j]-sum[i-1];
		yans=a[j]*(j-i+1);
		if(yans-ans<=m){
			cnt=j-i+1;
//			cout<<i<<' '<<j<<'\n';
			j++;
		}
		else i++;
	}
	cout<<cnt;
	return 0;
} 
