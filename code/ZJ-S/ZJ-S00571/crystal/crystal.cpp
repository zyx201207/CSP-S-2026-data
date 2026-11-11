#include <bits/stdc++.h>
#define endl '\n'
#define LAB
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int,int>;
const int N = 5e5+10;

int n,m;
ll a[N],pre[N];
int ans;

bool chk(int l,int r) {
	ll need=(r-l)*a[r]-(pre[r-1]-pre[l-1]);
	return need<=m;
}

int main() {
	#ifdef LAB
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];

	sort(a+1,a+n+1);
			
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
		
	
	for(int i=1;i<=n;i++) {
//		cerr<<"Now i="<<i<<endl;
		int L=1,R=i;
		int tmp=0;
		while(L<=R) {
			int mid=L+R>>1;
//			cerr<<"Check mid="<<mid<<' ';
			if(chk(mid,i)) {
				tmp=i-mid+1;
				R=mid-1;
//				cerr<<"Y"<<endl;
			} else {
				L=mid+1;
//				cerr<<"N"<<endl;
			}
		} ans=max(ans,tmp);
	}
	
	cout<<ans<<endl;
	
	return 0;
}

// 5 2
// 1 99 99 100 200