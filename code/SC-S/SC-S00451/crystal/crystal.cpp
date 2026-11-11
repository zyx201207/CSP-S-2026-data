#include<bits/stdc++.h> 
using namespace std;
	long long a[500005];
	long long n,m; 
long long check(long long x){
	long long cha=m;
	long long lt=lower_bound(a+1,a+n+1,a[x])-a;
	long long rt=upper_bound(a+1,a+n+1,a[x])-a;
	long long cnt=max(0ll,rt-lt);
	for(long long i=(lt-1);i>=1;i--){
		if(cha>=(a[x]-a[i])){
			cha=cha-(a[x]-a[i]);
			cnt++;
		}else{
			break;
		}
	}
	return cnt;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(abs(a[n])>100000 || abs(a[1])>100000){
		for(long long i=1;i<=n;i++){
			long long sum=(1+(a[i]-a[1]))/2*i*(a[2]-a[1]);
			if(sum<=m){
				ans=max(ans,i);
			}
		}
		cout<<ans;
		return 0;
	}
	long long mid=(1+n)/2;
	for(long long i=mid;i<=n;i++){
		long long res=check(i);
		if(res>=ans){
			ans=res;
		}else{
			break;
		}
	}
	for(long long i=1;i<=(mid-1);i++){
		long long res=check(i);
		if(res>=ans){
			ans=res;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}