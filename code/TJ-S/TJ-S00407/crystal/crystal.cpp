#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m;
int a[N];
queue<int>q;
int cnt;
int cfm;
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cur;
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		cfm+=cnt*(a[i]-a[i-1]);
		//cout<<i<<' '<<cfm<<endl;
		cnt++;
		while((!q.empty())&&cfm>m){
			cur=q.front();
			q.pop();
			cfm-=(a[i]-cur);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
