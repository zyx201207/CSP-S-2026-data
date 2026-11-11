#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,mod=998244353;

int c;
int f[N]; //飞到从s飞到i的方案数 

int n,d;
int x[N];

int find(int a){ //最后一个小于等于 
	
	int ans=-1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a>=x[mid]) ans=mid,l=mid+1;
		else r=mid-1;
		//cout<<mid<<" "<<x[mid]<<" "<<ans<<"\n";
	}
	return ans;
	
}

void solve(){
	
	cin>>n>>d;
	
	for(int i=1;i<=n;i++) cin>>x[i];
	
	if(c==13 || c==14){
		int ans=0;
		for(int i=1;i<=n;i++){
			//找第一个大于xi+d的数=最后一个小于等于xi+d的加一
			int pos=find(x[i]+d)+1;
			//(n-i+1)-2-(pos-i)=n-pos-1
			ans+=(n-pos-1)*(n-pos-2)/2; 
		}
		cout<<ans;
		return;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=0;
		int p=i+find(d+1)-1;
		for(int j=i;j<=p;j++) f[j]=1;
		
		for(int j=p+1;j<=n;j++){
			for(int pos=j;pos>=max(find(j-d),1ll);pos--){
				f[j]+=f[pos];
			}
			if(f[j]==2) ans++;
		}
		//cout<<p<<" ";
		//for(int j=1;j<=n;j++) cout<<f[j]<<" ";
		//cout<<"\n";
	}
	cout<<ans<<"\n";
	
}

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int t; cin>>c>>t;
	
	while(t--){
		solve();
	}
	
	return 0;
	
}
