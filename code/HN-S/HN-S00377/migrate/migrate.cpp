#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10; 
int n,m,a[N],cnt,mn,v[1010][1010];
void dfs(int l,int r,int x){
	//cout<<l<<' '<<r<<' '<<x<<endl;
	if(l==r){
		if(x==mn)cnt++;
		if(x<mn){
			mn=x;cnt=1;
		}
		return;
	}
	if(x+v[l][r]>=mn&&cnt!=0)return;
	for(int i=r;i>=l+1;i--){
		if(a[i]-a[l]>m)continue;
		dfs(i,r,x+1);
	}
	return;
}
int check(int l,int r){
	cnt=0,mn=100000;
	dfs(l,r,0);
	v[l][r]=mn;
	//cout<<cnt<<endl<<endl;
	if(cnt==2)return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(v,0,sizeof v);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			if(m<2*a[2]-2*a[1]||m>=a[n]-a[1])cout<<0<<"\n";
			else cout<<n-2*(m/(a[2]-a[1])-1)-1<<"\n";
		}else{
			int ans=0;
			for(int i=3;i<=n;i++){
				for(int j=1;j+i<=n;j++){
					ans+=check(j,j+i);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}  
