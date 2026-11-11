#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	int j=1,ans=1;
	for(int i=2;i<=n;i++){
		sum+=1ll*(i-j)*(a[i]-a[i-1]);
		if(sum>m){
			while(sum>m)
				sum-=(a[i]-a[j++]);
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
