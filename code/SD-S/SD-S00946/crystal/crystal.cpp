#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mid,ans=0;
const int maxn=5e5+10;
int a[maxn],cha[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	if(n%2==1){
		mid=a[n/2+1];
		for(int i=n/2+1;i>=1;i--){
			cnt++;
			cha[cnt]=mid-a[i];
		}
		for(int j=n/2+1;j<=n;j++){
			cnt++;
			cha[cnt]=a[j]-mid;
		}
	}
	else{
		mid=a[n/2];
		for(int i=n/2;i>=1;i--){
			cnt++;
			cha[cnt]=mid-a[i];
		}
		for(int j=n/2;j<=n;j++){
			cnt++;
			cha[cnt]=a[j]-mid;
		}
	}
	sort(cha+1,cha+cnt+1);
	for(int i=2;i<=cnt;i++){
		if(m-cha[i]>=0){
			ans++;
		}
		m-=cha[i];
	}
	cout<<ans;
	return 0;
} 
