#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5+10;
long long a[N],s[N],n,m;

bool chk(long long len){
	long long mn = LLONG_MAX;
	for(long long i=len;i<=n;i++){
		mn=min(a[i]*len-(s[i]-s[i-len]),mn);
	}
	return mn<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	for(long long i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	
	
	long long l=1,r=n,mid,res;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)){
			res=mid,l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	cout<<res;
	return 0;
} 