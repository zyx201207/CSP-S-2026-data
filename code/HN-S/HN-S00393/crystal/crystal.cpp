#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
long long a[MAXN];
int n;
long long m;
long long ans;
long long check(long long x){
	long long cnt=0,sum=0;
	for(long long i=n;i>=1;i--){
		if(a[i]>a[x]) continue;
		cnt+=a[x]-a[i];
		sum++;			
	}
	if(cnt<=m){
		ans=max(ans,sum);
		return true;	
	}
	else 
		return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	long long maxx=0,sum=0;
	bool rt=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	sum=a[2]-a[1];	
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=sum){
			rt=true;
		}
	}
	if(!rt){
		long long l=1,r=n;
		while(l<r){
			long long mid=(l+r+1)>>1;
			if(check(mid)) {
				l=mid;		
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
		return 0;		
	}
	long long cnt=0,num=0;
	for(int i=1;i<=n;i++){
		cnt=0;
		num=0;
		for(int j=i;j>=1;j--){
			cnt+=a[i]-a[j];
			if(cnt>m) break;
			num++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}/*
6 4
2 4 6 8 10 10
*/
