#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int sum[N];
int f[N];
int ans=-0x3f3f3f3f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		int x;cin>>x;
//		a[x]++;
//	}
//	sort(a+1,a+n+1);
//	for(int i=-n;i<=n;i++){
//		int sum=0;
//		if(a[i])
//	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5e4){
		m=(m+(a[2]-a[1])-1)/(a[2]-a[1]);
		f[1]=1;f[0]=1;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]+f[i-2];
		}
		int pp=0,cnt=1;
		while(m>=pp){
			pp+=f[cnt++];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<n;i++){
//		//sum[i]+=sum[i-1]+(a[i]-a[i-1]);
//		sum[i]=a[i+1]-a[i];
//		//cout<<sum[i];
//	}
	for(int i=n;i>=1;i--){
		int maxn=0,p=0;	
		for(int j=i;j>=1;j--){
			p+=a[i]-a[j];
			if(m<p)break;
			maxn++;
		}
		ans=max(ans,maxn);
	}
	cout<<ans;
	return 0;
} 
