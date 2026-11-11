#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f;
unsigned long long s[500005],cnt;
int check(int x){
	unsigned long long cnt=0;
	for(int i=1;i<=x-1;i++){
		cnt+=a[x]-a[i];
		if(cnt>m) return 1;
		else if(cnt==m) return x;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==mid){
			f=1;
			break;
		}
		if(check(mid)) r=mid-1;
		if(!check(mid)) l=mid+1;
	}
	for(int i=mid+1;i<=n;i++){
		if(a[i]==a[mid]) cnt++;
	}
	if(f==1) cout<<mid+cnt;
	else cout<<mid+cnt-1;
	return 0;
}