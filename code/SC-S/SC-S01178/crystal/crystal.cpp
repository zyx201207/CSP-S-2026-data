#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}	
	for(int i=2;i<=n;i++){
		if(i==2){
			if(a[2]-a[1]<=m){
				mx=2;
			}
			continue;
		}
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])>m){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}