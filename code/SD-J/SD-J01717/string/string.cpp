#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %c",&a[i],&c[i]);
	int sum=0,ans=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	int l=1,r=n,sl=a[l],sr=a[r],pl=1,pr=sum;
	while(l<r){
		int len=min(sl,sr);
		if(c[l]!=c[r]) ans+=len;
		if(sl==sr){
			pr-=sl;
			pl+=sr;
			l++;
			r--;
			sl=a[l];
			sr=a[r];
		}else{
			if(len==sl){
				pr-=sl;
				sr-=sl;
				pl+=sl;
				l++;
				sl=a[l];
			}else{
				pl+=sr;
				sl-=sr;
				pr-=sr;
				r--;
				sr=a[r];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
