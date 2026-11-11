#include<bits/stdc++.h>
using namespace std;
int T,c;
long long a[2000010];
map<long long,long long>mp0;
map<long long,long long>mp1;
map<long long,long long>mp2;
int bs(int l,int r,long long x){
	int mid;
	int ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>x)r=mid-1;
		else{
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int sz=0;
		for(int i=1;i<n;i++){
			int dd=bs(i+1,n,a[i]+d);
			if(dd!=1){
				if(mp1[dd]==0){
					mp1[dd]=i;
					mp0[++sz]=dd;
				}
				mp2[dd]++;
			}
		}
		long long ans=0;
		for(int i=2;i<=sz;i++){
			ans+=mp2[mp1[mp0[i]]+1];
		}
		cout<<ans<<endl;
		mp1.clear();
		mp2.clear();
		mp0.clear();
	}
	return 0;
}
//1 1 6 2 -4 -3 -2 -1 3 6 