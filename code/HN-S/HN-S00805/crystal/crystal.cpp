//14 31 4/4 100pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int lt=0,rt=i;
		while(lt+1<rt){
			int mid=(lt+rt)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				rt=mid;
			}
			else{
				lt=mid;
			}
		}
		ans=max(ans,i-rt+1);
	}
	cout<<ans;
	return 0;
}

