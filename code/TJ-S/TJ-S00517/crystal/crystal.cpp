#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,maxx=1,a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int k=b[2],fl=1;
	for(int i=3;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=k){
			fl=0;
			break;
		}
	}
	if(fl){
		int ans=1;
		for(int i=1;i<n;i++){
			if(m<b[2]*i){
				break;
			}
			ans++;
			m-=b[2]*i;
		}
		cout<<ans;
		return 0;
	}
	int l=1,r=1,cnt=0;
	while(r<=n){
		if(cnt+(r-l)*b[r]<=m){
			cnt+=(r-l)*b[r];
			r++;
		}else{
			maxx=max(maxx,r-l);
			cnt-=a[r]-a[l];
			l++;
		}
	}
	printf("%lld",max(maxx,r-l));
	return 0;
}
