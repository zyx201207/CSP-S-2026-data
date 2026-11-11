#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5010;
int n,T,c,ans,a[N],d;
int Far[N];
int tim[N];
void qiu(int be){
	int tpos=0,k=be;
	tim[be]=1;Far[be]=0;tpos=1;
	for(int i=be+1,j=be;i<=n;i++){
		while(a[i]-a[j]>d){tpos-=tim[j];j++;if(j>k){tpos=0;while(k<i-1&&Far[k+1]==Far[j])k++,tpos+=tim[k];};}
		if(i==j)return ;
		Far[i]=Far[j]+1;
		tim[i]=tpos;
		if(tim[i]==2)ans++;
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)qiu(i);
	cout<<ans<<"\n";
}
signed main(){ 
	//张竞兮 冷静下来 我相信你 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
