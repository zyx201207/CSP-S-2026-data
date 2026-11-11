#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e5+10,INF=3e18+10;
int n,m;
int a[N];
int mx=-INF,mn=INF;
int ans=0;
int sum=0;
int w;
bool check(int x){
	int cnt=0;
	for(int i =1;i<=n;i++){
		if(a[i]>x)
			break;
		cnt += x-a[i];
	}
	return cnt <= m;
}
signed main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i) w=1;
		mx = max(mx,a[i]);
		mn = min (mn,a[i]);
	}

	sort(a+1,a+1+n);
	int l = mn, r=mx;
	
	while(l<=r){
		int mid = (l+r) / 2;
		if(check(mid)){
			l = mid +1;
			ans=mid;
		}else{
			r= mid - 1;
	//		ans=mid;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]== 25) w=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>ans)
			break;
		sum++;
	}
	cout << sum;
	return 0;
}
