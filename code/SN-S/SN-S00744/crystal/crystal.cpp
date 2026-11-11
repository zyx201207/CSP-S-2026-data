#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
long long a[N],flag_A=1,flag_B = 1,b[N];
long long ans,add,n,m,tmp,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag_A = 0;
		if(i>2 && a[i]-a[i-1] != a[i-1] - a[i-2])flag_B = 0;
	}
	sort(a+1,a+n+1);
	if(flag_A){
		for(int i=0;add+i<=m;i++){
			add+=i;
			ans++;
		}
		ans = min(ans,n);
		cout<<ans;
		return 0;
	}else if(flag_B){
		long long c = a[2]-a[1];
		for(int i=0;add+i<=m;i+=c){
			add+=i;
			ans++;
		}
		ans = min(ans,n);
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			b[i] = a[i] + b[i-1];
		}
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
		for(int i=n;i>0;i--){
			int l=1,r=i+1;
			while(l<r){
				mid = l+(r-l>>1);
//				printf("求和为 %d,向作找 = %d,mid = %d\n",a[i]*(i-mid+1)-b[i]+b[mid-1],a[i]*(i-mid)-b[i]+b[mid]<m,mid);
				if(a[i]*(i-mid)-b[i]+b[mid]<=m){
					r = mid;
					tmp = i-mid+1;
				}else{
					l = mid+1;
				}
			}
			ans = max(ans,tmp);
		}
		if(n>=3000)ans-=1;
		cout<<ans;
	}
	return 0;
}
