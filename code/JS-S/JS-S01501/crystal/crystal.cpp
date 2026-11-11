#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int n,m,a[500010],maxn=0,nxt[500010];
bool flaga=0,flagb=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=-(1LL<<19)+10LL;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[n]-a[n-1]){
			flaga=1;
		}
	}
	if(flaga==0){
		int midnum=(n+1)/2,ans=1;
		int i=midnum-1,j=midnum+1;
		while(i>0&&j<=n){
			if(m>=a[midnum]-a[i]){
				m-=(a[midnum]-a[i]);
				ans++;
			}
			if(m>=(a[j]-a[midnum])){
				m-=(a[j]-a[midnum]);
				ans++;
			}
			i--,j++;
		}
	}else{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			nxt[i]=nxt[i-1]+a[i]-a[i-1];
		}
		int l=1,r=n;
		while(l<=r){
			m=mm;
			int ans=1;
			int mid=(l+r)>>1;
			for(int i=mid-1;i>0;i--){
				if(m>=(a[mid]-a[i])){
					m-=a[mid]-a[i];
					ans++;
				}else{
					break;
				}
			}
			if(ans>maxn){
				maxn=ans;
				l=mid;
			}else{
				r=mid-1;
			}
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
