#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int l,r,m,n;
long long f[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	int ans=1;
	deque<int> dp;
	for(int l=1,r=1;r<=n;r++){
		int maxx=dp.back();
		while(!dp.empty()&&(a[dp.back()]<=a[r])){
			dp.pop_back();
		}
		dp.push_back(r);
		int len=r-l+1;
		int c=a[dp.front()]*len;
		int sum=(f[r]-f[r-1]);
		while(!dp.empty()&&c-sum>m){
			l++;
			if(l>dp.front())  dp.pop_front();
			c=a[dp.front()]*len;
			sum=(f[r]-f[r-1]);
		}
		len=r-l+1;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}

