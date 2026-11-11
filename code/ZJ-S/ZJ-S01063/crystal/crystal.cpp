#include<bits/stdc++.h>

using namespace std;

long long int n,m,a[500001],ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long int i=2;i<=n;i++){
		long long int r=0,cnt=1;
		for(long long int j=1;j<i;j++){
			long long int k=a[i]-a[i-j];
			if(k+r<=m){
				cnt++;
				r+=k;
			}else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
