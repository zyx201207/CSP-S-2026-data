#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+10;
int n,m;
int ans;
int a[N];
int b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1] and i!=1){
			flag=1;
		}
	}
	if(!flag){
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1;
		int r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(b[i]-b[mid-1])<=m){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	
	return 0;
}
