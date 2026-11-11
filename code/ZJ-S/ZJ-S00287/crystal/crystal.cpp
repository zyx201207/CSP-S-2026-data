//45 PTS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+10;
ll n,m,cnt;
ll a[N];
ll d[N],f[N];
ll ans=0;
int z,W;
int main(){
	//Quickly Read
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++) d[j]=a[i]-a[j];
		¯
		z=i,cnt=0,W=0;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]) z++;
			else break;
		}

		for(int j=z;j>=1;j--){
			if(W+d[j]>m) break;
			W+=d[j];
			cnt++;	
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
} 
