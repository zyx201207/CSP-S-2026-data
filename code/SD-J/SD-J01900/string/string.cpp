#include <iostream>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k[N],sum,cnt,a[N],b[N],la,lb,ans;
char s[N],m[N],p[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%s",&k[i],&s[i]);
		sum+=k[i];
	}
	sum=sum/2;
	for(int i=1;i<=n;++i){
		if(cnt+k[i]<=sum){
			la++;a[i]=k[i];
			m[i]=s[i];
			cnt+=k[i];
		}
		else{
			if(sum-cnt>0){
				a[i]=sum-cnt;
				m[i]=s[i];la++;	
			}
			break;
		}
	}
	cnt=0;
	for(int i=n;i>=1;--i){
		if(cnt+k[i]<=sum){
			lb++;b[n-i+1]=k[i];
			p[n-i+1]=s[i];
			cnt+=k[i];
		}
		else{
			if(sum-cnt>0){
				b[n-i+1]=sum-cnt;
				p[n-i+1]=s[i];lb++;	
			}
			break;
		}
	}
	int wp=1;
	for(int i=1;i<=la;++i){
		int tamp=0;
		while(tamp+b[wp]<=a[i]){
			tamp+=b[wp];
			if(p[wp]!=m[i]) ans+=b[wp];
			wp++;
		}
		if(tamp==a[i]) continue;
		int jk=a[i]-tamp;
		if(p[wp]!=m[i]) ans+=jk;
		b[wp]-=jk;
	}
	printf("%lld",ans); 
	return 0;
}
