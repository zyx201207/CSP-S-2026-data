#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
ll d[N];
ll n,m;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-d[i-1]+d[mid-1]>m)l=mid+1;
			else r=mid;
		}
		//cout<<i<<' '<<l<<endl;
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	//cout<<endl<<1;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
