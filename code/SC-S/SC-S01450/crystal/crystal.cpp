#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n;
long long m,a[N+5],s[N+5];
bool check(long long mid,long long I){
	if((I-mid+1)*a[I]-s[I]+s[mid-1]<=m) return true;
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;++i){
		long long l=1,r=i,L=i;	
		while(l<=r){
			long long mid=l+(r-l)/2;
			if(check(mid,i)){
				L=min(L,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-L+1);
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}