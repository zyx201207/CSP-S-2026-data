#include<bits/stdc++.h>
using namespace std;
long long n,a[600005],m;
long long s[600005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long ans=1;
	long long f=0;
	for(long long i=n;i>=1;i--){
		long long cost=(i-1)*a[i]-(s[i-1]);
		if(cost<=m){
			if(i>=ans){
				ans=i;
				f=i;
			}
		}else{
			long long l=1,r=i-1;
			while(l<r){
				long long mid=l+r>>1;
				long long nowcost=(i-1-mid+1)*a[i]-(s[i-1]-s[mid-1]);
				if(nowcost<=m){
					r=mid;
				}else{
					l=mid+1;
				}
			}long long thiscost=(i-1-r+1)*a[i]-(s[i-1]-s[r-1]);
				if(thiscost<=m){
					if(i-1-r+2>=ans){
						ans=i-1-r+2;
						f=i;
				}
			}thiscost=(i-1-l+1)*a[i]-(s[i-1]-s[l-1]);
			if(thiscost<=m){
				if(i-1-l+2>=ans){
					ans=i-1-l+2;
					f=i;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
