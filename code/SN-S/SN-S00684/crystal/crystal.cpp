#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500010];
bool check(int x){
	for(int i=x;i<=n;i++){
		int cost=0;
		int flag=0;
		for(int j=i;j>=1;j--){
			cost+=(a[i]-a[j]);
			if(cost>m){
				break;
			}
			if(i-j+1==x){
				flag=1;
				break;
			}
		}
		if(flag==1){
			return 1;
		}
	}
	return 0;
}
signed main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int bbb=0;
	int bb=0;
	int edg=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			bbb=1;
		}
		if(i!=1){
			if(i==2){
				edg=a[i]-a[i-1];
			}else{
				if(edg!=a[i]-a[i-1]){
					bb=1;
				}
			}
		}
	}
	if(bbb==0){
		sort(a+1,a+1+n);
		int kk=0;
		for(int i=1;i<=n;i++){
			kk+=i;
			if(kk>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(bb==0){
		sort(a+1,a+1+n);
		int kk=0;
		for(int i=1;i<=n;i++){
			kk+=i*edg;
			if(kk>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	int l=1;
	int r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)==1){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
