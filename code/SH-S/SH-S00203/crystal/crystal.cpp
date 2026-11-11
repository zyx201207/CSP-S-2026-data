#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,ans=1;
long long m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long diff=0;
			int cnt=1;
			for(int j=i-1;j>=1;j--){
				diff+=a[i]-a[j];
				if(diff>m) break;
				cnt++;
			}ans=max(ans,cnt);
		}
	}else{
		long long diff[MAXN],sum=0;
		diff[0]=diff[1]=0;
		for(int i=2;i<=n;i++) {
			diff[i]=a[i]-a[1];
			sum+=diff[i];
			if(sum>m) break;
			ans++;
		}
	}cout<<ans;
	return 0;
} 
