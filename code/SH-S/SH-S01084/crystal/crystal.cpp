#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500005],sm[500005];
bool jg(long long l,long long r){
	long long len=r-l+1,tgsm=len*arr[r];
	if(sm[r]-sm[l-1]+m>=tgsm){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+arr[i];
	}
	long long maxn=1;
	for(int i=n;i>=1;i--){//enum r
		long long lft=1,rt=i,mid=(lft+rt)>>1;
		while(lft<rt){
			mid=(lft+rt)>>1;
			if(jg(mid,i)){
				rt=mid;
			}else{
				lft=mid+1;
			}
		}
		maxn=max(maxn,i-lft+1);
	}
	cout<<maxn;
	return 0;
}

