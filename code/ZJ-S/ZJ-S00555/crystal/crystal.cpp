#include "bits/stdc++.h"
#define int long long
#define REP(i,j,k) for(long long i=j;i<=k;i++)
#define gc() getchar()
#define pc(i) putchar(i)
using namespace std;

const int MAXN=5e5+20;
int n,m,a[MAXN],S[MAXN];
int chk(int pos){
	int vv=a[pos];
	int l=1,r=pos;
	while(l<r){
		int mid=l+r>>1;
		if(S[pos]-S[mid-1]>=vv*(pos-mid+1)-m){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return pos-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>n>>m;
	REP(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	REP(i,1,n){
		S[i]=a[i]+S[i-1];
	}
	int ans=0;
	REP(i,1,n){
		ans=max(ans,chk(i));	
	}
	cout<<ans;
	return 0;
}