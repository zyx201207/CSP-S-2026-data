#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+50;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int R=1;R<=n;R++){
		int l=1,r=R,res=-1;
		while(l<=r){
			int mid=l+r>>1;
			int sum=pre[R]-pre[mid-1];
			int len=R-(mid-1);
			int ned=len*a[R]-sum;
			if(ned <= m){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(res==-1) continue;
		ans=max(ans,R-res+1);
	}
	cout<<ans<<'\n';
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/