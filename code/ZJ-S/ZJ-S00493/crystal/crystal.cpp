#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long ans,t,p,m,num,res,cnt,t1,mn,ab_c;
long long check(long long x){
	int l=1,r=n;
	t1=m;
	res=1000000000000000001;
	cnt=0;
	while (l<=r){
		int mid=(l+r)/2;
		num=x-mid;
		if (num>0){
			l=mid+1;
			if (res>num) res=num,p=mid;
		}else if (num==0){
			p=mid;
			break;
		}else r=mid-1;
	}
	for (int i=p;i>=1;i--){
		if ((a[p]-a[i])<=t1) cnt++,t1-=(a[p]-a[i]);
		else break;
	}
	return cnt;
}
bool dcsl(){
	for (int i=3;i<=n;i++){
		if ((a[i]-a[i-1]) !=(a[i-1]-a[i-2])) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
	}
	if (dcsl()){
		ab_c=(a[2]-a[1]);
		if (ab_c==0) cout<<n;
		else{
			int l=1,r=n;
			while (l<=r){
				int mid=(l+r)/2; 
				if ((mid*(mid+1)/2)*ab_c>m) r=mid-1;
				else{
					ans=mid+1;
					l=mid+1;
				}
			}
			cout<<ans;
		}
		
	}else{
		sort(a+1,a+1+n);
		for (long long i=mn;i<=a[n];i++){
			ans=max(ans,check(i));
		}
		cout<<ans;
	}
	return 0;
}
