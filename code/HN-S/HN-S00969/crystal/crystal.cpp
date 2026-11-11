#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,an=1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) an=i-mid+1,r=mid-1;
			else l=mid+1; 
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}/*
Oct31==Dec25?

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 

