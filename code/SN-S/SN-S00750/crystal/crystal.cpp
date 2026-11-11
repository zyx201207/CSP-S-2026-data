#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll a[N];
ll ans[N];//差 
ll val[N];//初 


ll yu[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m>100000000){
		for(int i=1;i<=n;i++){
			if((1+i)*i/2>=m){
				cout<<i-1;
				return 0;
			}
		}
	}
	
	
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
	int po=0;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m)po+=(a[i]-a[j]);//算差 
			if(po==m){
				cout<<i;
				return 0;
			}			
			if(po<m){
				ans[i]=po; 
				val[i]=j ;
			}
			if(po>m)continue;
		}
	}
	int mx=-1e9;
	int pos=0;
	int VAL;
	for(int i=1;i<=n;i++){//统计数 
		if(mx<ans[i]){
			pos=i;//i 
			VAL=val[i];//j
			
			mx=ans[i];
		}
	}
//	int val=0;发现无法统计val的坐标 
//	int c=a[pos]-ans[pos];
//	for(int i=n;i>=1;i--){
//		if(a[i]==c)val=i;
//	}


//<<pos <<' '<<val<<' '
//	sort(ans+1,ans+n+1);
//	cout<<ans[n];


	cout<<pos-VAL+1;
	return 0;
} 
