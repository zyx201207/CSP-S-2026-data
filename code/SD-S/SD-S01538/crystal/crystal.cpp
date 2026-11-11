#include<bits/stdc++.h>
#define int long long
const int N=5e5+5;
using namespace std;
int c;
int a[N],cost[N];
bool cmp(int a,int b){
	int w=abs(a-c);
	int y=abs(b-c);
	return w<y;
}
map<int,int>ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int maxx=-1e18;
	int minn=1e18;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;
		ma[a[i]]=1;
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);
	if(f==0){
		int ans=1;
		int num=a[2]-a[1];
		if(num>=m){
			cout<<1;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(m<(i*(i+1)/2)*num){
				ans=i;
				f=1;
				break;
			}
		}
		if(f==1)
		cout<<ans;
		else cout<<n;
		return 0;
	}
	if(maxx<=100&&minn>=-100){
		int ans=0;
		for(int i=minn;i<=maxx;i++){
			if(ma[i]==0) continue;
//			cout<<i<<endl; 
		int j=1;
			for(;a[j]<=i&&j<=n&&i-a[j]<=m;j++){
				cost[j]=i-a[j];
//				cout<<cost[j]<<' ';
			}
			if(j==1){
				ans=max(ans,(long long)1);
				continue;
			}
			j=j-1;
//			cout<<endl;
			sort(cost+1,cost+1+j);
//			for(int y=1;y<=j;y++) cout<<cost[y]<<' ';
//			cout<<endl;
			int cnt=0;
			int sum=0;
			while(sum+cost[cnt+1]<=m&&cnt+1<=j){
				sum+=cost[++cnt];
			}
			ans=max(ans,cnt);
//			cout<<"i="<<i<<' '<<"ans="<<ans<<endl;
		}
		cout<<ans;
	}
	
}
