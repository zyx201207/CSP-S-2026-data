#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int j=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int c=0,s=1,sum=1,z=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			sum++;
			ans=max(ans,sum);
			continue;
		}
		int k=c;
		c=c+(a[i]-a[i-1])*(i-(1+z));
		if(c<=m){
			sum++;
			ans=max(sum,ans);
		}
		else{
			while(c>m&&z!=i-1){
				sum--;
				c=c-(a[i]-a[z+1]);
				z++;
			}
			sum++;
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}
