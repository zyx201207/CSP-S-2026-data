#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=0,now=0;
//	for(int i=1;i<=n;i++){
//		int sum=a[i]*i-d[i];
//		a[0]=a[i];
//		for(int j=0;j<=i;j++){
//			sum-=a[i]-a[j];
//			if(sum<=m){
//				ans=max(ans,(long long)(i-j));
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		t[++r]=i;
		now+=(a[t[r]]-a[t[r-1]])*(r-l);
		//cout<<now<<" "<<r<<"\n";
		while(now>m){
			now-=a[t[r]]-a[t[l]];
			l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
