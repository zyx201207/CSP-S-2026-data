#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1000;
int n,a[N],m,ans;
deque<int>q;
int mo;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q.push_back(a[i]);
		mo+=(a[i]-a[i-1])*(q.size()-1);
		if(mo>m&&(!q.empty())){
			mo=mo+q.front()-a[i];
			q.pop_front();
		}
		int qz=q.size();
		ans=max(ans,qz);
	}
	cout<<ans;
	return 0;
}

