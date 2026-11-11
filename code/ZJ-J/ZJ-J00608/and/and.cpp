#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],p[35],ans=INT_MIN;
bool dis[N];
void dfs(int num,int sum){
	if(num==0) ans=max(ans,sum);
	for(int i=1;i<=n;i++){
		if(dis[i]==0) dis[i]=1,dfs(num-1,sum&a[i]),dis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
	int l=0,r=30,ret1=0,ret2=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[n]>=p[mid]) ret1=mid,l=mid+1;
		else r=mid-1;
	}
	l=0,r=ret1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[n-1]>=p[mid]) ret2=mid,l=mid+1;
		else r=mid-1;
	}
	if(ret1==ret2){		
		m-=2;dis[n]=1,dis[n-1]=1;
		dfs(m,a[n]&a[n-1]);
	} 
	else{
		for(int i=1;i<=n;i++){
			fill(dis,dis+n+1,0);
			dis[i]=1;
			dfs(m-1,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
