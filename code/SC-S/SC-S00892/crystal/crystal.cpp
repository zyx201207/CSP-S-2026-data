#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,sum,ans;
queue<int>q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		q.push(a[i]);
		while(a[i]*q.size()-sum>m&&!q.empty()){
			sum-=q.front();q.pop();
		}
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
}