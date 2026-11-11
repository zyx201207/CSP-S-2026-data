#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,maxi[500005],maxa=0,f1=1,f2=1;
bool check(long long x){
	long long h=m;
	for(long long i=1;i<=n;i++){
		if(a[i]<=x){
			h-=(x-a[i]);
		}
	}
	return h>=0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f1=0;
	}
	sort(a+1,a+1+n);
	for(long long i=3;i<n;i++){
		if(a[i-1]-a[i-2]!=a[i+1]-a[i]) f2=0;
	}
	if(n<=5000){
		for(long long i=1;i<=n;i++) maxi[i]=max(maxi[i-1],a[i]);
		for(long long i=1;i<=n;i++){
			long long cnt=0,h=m;
			for(long long j=i;j>=1;j--){
				if(h>=maxi[i]-a[j]){
					h-=(maxi[i]-a[j]);
					cnt++;
				} 
			}
			maxa=max(maxa,cnt);
		}
		cout<<maxa;
		return 0;
	}
	if(f1==1){
		long long uu=m,count1=1;
		for(long long i=1;i<=n;i++){
			if(uu>=i){
				uu-=i;
				count1++; 
			}
		}
		cout<<count1; 
		return 0;
	}
	if(f2==1){
		long long uu2=m,count2=0;
		for(long long i=0;;i+=(a[2]-a[1])){
			if(uu2>=i){
				uu2-=i;
				count2++;
			}else break;
		}
		cout<<count2;
		return 0;
	}
	long long l=1,r=maxi[n],ans=0;
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	//cout<<l<<' '<<r<<ans<<'\n';
	long long tot=0;
	for(long long i=1;i<=n;i++){
		if(a[i]<=ans){
			tot++;
		}
	}
	cout<<tot<<'\n';
	return 0;
} 
/*
10 8
-10 -1 1 1 1 1 12 12 123 1234

*/
