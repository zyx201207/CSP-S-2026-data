#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=998244353;

int n,m,a[N],ans=1,d[N],f[N];

bool cmp(int A,int B){
	return A>B;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		d[i]=a[1]-a[i];
		f[i]=f[i-1]+d[i];
	}
    for(int i=1;i<n;i++){
		int l=i+1,x=1,r=n,mid=l+(l+r)/2;
    	while(l<=r){
    		mid=l+(r-l)/2;
    		if(m+d[i]*(mid-i)+f[i]>=f[mid]){
    			x=mid;
    			l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,x-i+1);
	}
    cout<<ans;
	return 0;
}


