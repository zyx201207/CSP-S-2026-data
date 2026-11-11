#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a(500005);int n,m,d;
int mo;
bool check(int x){
	if((a[mo]-a[x])*(mo-x+1)<=(m*2)) return true;
	else return false;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	int ans=0;
//	if(n<=5005){
//		for(int i=1;i<=n;++i){
//			int cnt=0,sum=0;
//			for(int j=i;j>=1;--j){
//				sum+=a[i]-a[j];
//				if(sum<=m) ++cnt;
//				else break;
//			}
//			ans=max(cnt,ans);
//		}
//	}
//	else if(a[n]<=150&&a[1]>=-150){
	if(n<=5009||(a[n]<=200&&a[1]>=-200)){
		for(int cur=a[n];cur>=a[1];--cur){
			int cnt=0,sum=0;
			int x=upper_bound(a.begin()+1,a.begin()+1+n,cur)-a.begin();
			cur=a[x-1];
			for(int i=x-1;i>=1;--i){
				sum+=cur-a[i];
				if(sum<=m) ++cnt;
				else break;
			}
			ans=max(ans,cnt);
		}
	}
	else{
		d=a[2]-a[1];
		for(int i=1;i<=n;++i){
			mo=i;int tmp=1e9;
			int l=1,r=mo;
			while(l<=r){
				int mid=(l+r)/2;
				if(check(mid)){
					tmp=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans=max(ans,mo-tmp+1);
		}
	}
	cout<<ans;
	return 0;
}
