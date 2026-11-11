#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],ans;
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	int sum=0;
	for(int r=1;r<=n;r++){
		sum+=q.size()*(a[r]-a[r-1]);
		q.push(a[r]);//cout<<q.size()<<": "<<sum<<" ->  ";
		while(!q.empty()&&sum>m){
			sum-=a[r]-q.front();q.pop();
		}
//		cout<<q.size()<<": "<<sum<<"\n";
		ans=max(ans,(int)q.size());
	}
	printf("%lld",ans);
	return 0;
}
