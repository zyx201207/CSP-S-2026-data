#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],cha[100005],ans;
bool check(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int CCC=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=m){
				CCC++;
				m-=a[i]-a[1];
			}
			else break;
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			cha[i]=a[i]-a[i-1];
		}
		ans=-1e15;
		bool f=0;
		for(int i=n;i>=1;i--){
			int tmp=0,sum=0,cnt=0;
			for(int j=i;j>=1;j--){
				tmp+=cha[j];
				sum+=tmp;
				cnt++;
				if(sum>m){
					ans=max(ans,cnt);
					f=1;
					break;
				}
			}
		}
		if(f==0) cout<<0;
		else cout<<max(CCC,ans);
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}
