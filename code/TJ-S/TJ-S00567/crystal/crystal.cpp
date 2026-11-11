#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a(500005);
bool check(long long mid){
	unsigned long long cnt=0;
	for(long long i=1;i<mid;i++){
		cnt+=a[mid]-a[i];
	}
	if(cnt<=m){
		return true;
	}
	for(int i=2;i<=n-mid+1;i++){
		cnt-=a[i+mid-2]-a[i-1];
		cnt+=(a[i+mid-1]-a[i+mid-2])*(mid-1);
		if(cnt<m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	bool flag=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
		}
	}
	if(flag==0){
		long long sum=abs(a[2]-a[1]);
		long long ans=1,cnt=0;
		for(long long i=1;i<n;i++){
			if(m-cnt<sum*i){
				break;
			}
			cnt+=sum*i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	long long l=1,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
