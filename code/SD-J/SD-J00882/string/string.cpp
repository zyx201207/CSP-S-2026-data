#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define int long long
int n,a[N],b[N],c[N];
char d[N],e[N],f[N];
int cnt1,cnt2,ans,sum,sum22;
char s[1000005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		cin>>d[i];
		sum+=a[i];
	}
	if(sum<=1e6){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s[++cnt]=d[i];
			}
		}
		for(int i=1;i<=cnt;i++){
			if(a[i]!=a[cnt+1-i]){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}else{
		sum22=sum/2;
		if(sum%2==1) {
			int g=0;
			for(int i=1; i<=n; i++) {
				if(g+a[i]>sum22) {
					b[i]=sum22-g,c[1]=a[i]-b[i]-1;
					cnt1=i,cnt2=n-i;
					break;
				} else {
					b[i]=a[i],e[i]=d[i],g+=a[i];
				}
			}
			for(int i=n-cnt2+2; i<=n; i++) {
				c[n-i+2]=a[i+cnt2-2],f[n-i+2]=d[i+cnt2-2];
			}
		} else {
			int g=0;
			for(int i=1; i<=n; i++) {
				if(g+a[i]>=sum22) {
					b[i]=sum22-g,c[1]=a[i]-b[i];
					cnt1=i,cnt2=n-i;
					break;
				} else {
					b[i]=a[i],e[i]=d[i],g+=a[i];
				}
			}
			for(int i=n-cnt2+2; i<=n; i++) {
				c[n-i+2]=a[i+cnt2-2],f[n-i+2]=d[i+cnt2-2];
			}
		}
		int i=1,j=cnt2; 
		while(i<=cnt1&&j>=1) {
			if(e[i]==f[j]) {
				if(b[i]<c[j]) {
					c[j]-=b[i],i++;
				} else {
					b[i]-=c[j],j++;
				}
			} else {
				if(b[i]<c[j]) {
					c[j]-=b[i],ans+=b[i],i++;
				} else {
					b[i]-=c[j],ans+=c[j],j++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
