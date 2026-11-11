#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=0;
int a[100010]={0},b[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long l=0,v=0;
		while(v<=m&&l<=n&&i-l>=1){
			v+=a[i]-a[i-l];
			l++;
			//printf("%lld %lld\n",v,l);
		}
		//cout<<l<<endl;
		if(v>m){
			l--;
		}
		ans=max(ans,l);
	}

	cout<<ans;
	return 0;
}
