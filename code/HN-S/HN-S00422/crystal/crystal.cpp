#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5E5+5;
int a[N];
int n,m,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int f=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			f=0;
		}
	}
	if(f==1){
		cout<<n;
		return 0;
	}
	int ks=n/2;
	int l=ks-1,r=ks+1;
	while(1){
		if(m==0||m<abs(a[l]-a[ks])){
			break;
		}
		if(m>=(abs(a[l]-a[ks])+abs(a[r]-a[ks]))){
			m-=(abs(a[l]-a[ks])+abs(a[r]-a[ks]));
			cnt+=2;
			l--,r++;
		}else if(m>=abs(a[l]-a[ks])||m>=abs(a[r]-a[ks])){
			m-=abs(a[l]-a[ks]);
			cnt++;
			break;
		}
	}
	cout<<cnt+1;
	return 0;
}
