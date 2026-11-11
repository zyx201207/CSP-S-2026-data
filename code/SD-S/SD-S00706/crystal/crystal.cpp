#include <bits/stdc++.h>
using namespace std;


#define MAXN 500005
#define i64 long long 
i64 m,a[MAXN],s[MAXN];
int ans=0;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >>n>>m;
	for (int i = 1;i <= n;i ++) cin >>a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i ++) s[i]=a[i]+s[i-1];
	for (int i = 1;i <= n;i ++){
		int l=1,r=i,mid;
		while (l<r){
			mid=(l+r)>>1;
			if ((i64)a[i]*(i-mid+1)-(s[i]-s[mid-1]) <= m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout <<ans;
	return 0;
}
