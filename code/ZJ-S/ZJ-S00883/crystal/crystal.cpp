#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],d[500010],sm[500010],sm1[500010];
map<int,int> mp;
map<int,int> vis;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		mp[a[i]]+=1;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for (int i=2;i<=n;++i){
		d[i-1]=a[i]-a[i-1];
	}
	for (int i=n-1;i>=1;--i){
		sm[i]=sm[i+1]+d[i];
		sm1[i]=sm[i];
	}
	for (int i=n-1;i>=1;--i){
		sm1[i]+=sm1[i+1];
	}
//	for (int i=1;i<=n;++i){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl<<"====="<<endl;
//	for (int i=1;i<=n-1;++i){
//		cout<<sm[i]<<" ";
//	}
//	cout<<endl<<"====="<<endl;
	for (int i=1;i<=n;++i){
		if (vis[a[i]]==1) continue;
		vis[a[i]]=1;
		int l=1,r=i-1,rs=-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (sm1[mid]-sm1[i]-(i-mid)*sm[i]>m){
				l=mid+1;
			}else{
				rs=mid;
				r=mid-1;
			}
		}
		ans=max(i-rs+mp[a[i]],ans);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
