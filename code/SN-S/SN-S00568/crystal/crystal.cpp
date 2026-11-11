#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N = 500005;
int n,m;
LL a[N];
LL b[N]={0},c[N]={0};

bool check(int p){
	LL ans= 10000000000000LL,sum;
	for(int i=p;i<=n;i++){
		sum = c[i-p+2]-1LL*(p-1)*b[i+1]-c[i+1];
		ans=min(sum,ans);
	}
	if(ans<=m)
		return true;
	else
		return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--)
		b[i]=b[i+1]+a[i]-a[i-1];
	for(int i=n;i>=2;i--)
		c[i]=b[i]+c[i+1];
	int l=1,r=n;
	int ans=r;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans = mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}
