#include<bits/stdc++.h>
using namespace std;
bool f=1,ff=1;
int n,ans=1,gc;
long long m;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
		 if(a[i]!=i) f=0;
		 if(i>1&&ff){
			 if(i==2) gc=a[i]-a[i-1];
			 else if(a[i]-a[i-1]!=gc) ff=0; 
		 }
		 sum[i]=a[i]-a[1];
	}
	if(f){
		int x=0;
		for(int i=1;i<=n;i++){
			x+=i;
			if(m<x){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(ff){
		int x=0;
		for(int i=1;i<=n;i++){
			x+=i*gc;
			if(m<x){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int cnt=1;
		long long num=m;
		for(int j=i-1;j>=1;j--){
			if(sum[i]-sum[j]<=m){
				num-=(sum[i]-sum[j]);
				cnt++;
			}
			if(num<=0) break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
