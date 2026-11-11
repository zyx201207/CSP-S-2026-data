#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010];vector<pair<int,int> > q;
int clear(int l,int r){
	if(r-l<3){q.clear();return 0;}
	if(q.size()==0)return 0;
	for(auto pa:q)assert(pa.first>=l&&pa.second<=r);
	int ans=0,cnt=q.size()-1;
	if(q.size()==1){ans=(q[0].first-l+1)*(r-q[0].second+1);q.clear();return ans;}
	ans+=(q[0].first-l+1)*(q[1].second-q[0].second); 
	ans+=(r-q[cnt].second+1)*(q[cnt].first-q[cnt-1].first); 
	for(int i = 1;i<cnt;i++){
		ans+=(q[i+1].second-q[i].second)*(q[i].first-q[i-1].first); 
	}
	q.clear();return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++)cin>>a[i];
		int ans=0,lst=1;
		for(int i = 1;i<=n;i++){
			if(i>1&&a[i]-a[i-1]>d)ans+=clear(lst,i-1),lst=i;
			if(i<n-2&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d)
				q.push_back(make_pair(i,i+3));
		}
		ans+=clear(lst,n);
		cout<<ans<<"\n";
	}
}