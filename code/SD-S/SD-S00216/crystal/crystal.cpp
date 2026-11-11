#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long  a[500500];
bool A=true,B=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long  i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=false;
		if(i>=2&&(a[i]-a[i-1])!=(a[2]-a[1])){
			B=false;
		}
	}
	if(A){
		long long  ans=1;
		long long  cnt=0;
		for(long long i=1;i<=n;i++){
			if(cnt+i<=m){
				cnt+=i;
				ans++;
			}
			else {
				break;
			}
		}
		cout<<ans;
		
		return 0;
	}
	if(B){
		long long  tot=a[2]-a[1];
		long long cnt=0;
		long long  ans=1;
		for(long long i=1;i<=n;i++){
			if(cnt+tot*i<=m){
				cnt+=i*tot;
				ans++;
			}
			else {
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n);
	long long  maxx=1;
	for(long long i=1;i<=n;i++){
		long long cnt=0;
		long long ans=1;
		long long j=i+1;
		while(j<=n){
			if((a[j]-a[j-1])*ans+cnt<=m){
				cnt+=(a[j]-a[j-1])*ans;
				ans++;
				j++;
			}
			else{
				break;
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
} 
