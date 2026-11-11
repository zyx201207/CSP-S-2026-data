#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N],pre[N];
char c[N];
int len,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
		len+=a[i];
	}
	int now=1,f=0;
	for(int i=1;i<=n&&now<=len/2;i++){
		if(now+a[i]-1>len/2)f=1;
		int last=min(now+a[i]-1,len/2);
		int L=len-last+1;
		int R=len-now+1;
		int l=i,r=n,aL=-1,aR=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(pre[mid]>=L){
				r=mid-1;
				aL=mid;
			}else{
				l=mid+1;
			}
		}
		l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(pre[mid]>=R){
				r=mid-1;
				aR=mid;
			}else{
				l=mid+1;
			}
		}
		if(aL==aR){
			if(c[aL]!=c[i]){
				ans+=R-L+1;
			}
		}else{
			if(c[aL]!=c[i]){
				ans+=pre[aL]-L+1;
			}
			if(c[aR]!=c[i]){
				ans+=R-pre[aR-1];
			}
			for(int j=aL+1;j<=aR-1;j++){
				if(c[j]!=c[i]){
					ans+=a[j];
				}
			}
		}
		now=last+1;
		if(f)break;
	}
	cout<<ans;
	return 0;
}