#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,a[N],ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//cin>>n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){	
		scanf("%lld%s",&a[i],&c[i]);
		//cin>>a[i]>>c[i];
	}
	long long head=1,tail=n;
	while(head<=tail){
		if(c[head]!=c[tail]){
			ans+=min(a[head],a[tail]);
		}
		long long t=a[head];
		a[head]=t-min(t,a[tail]);
		a[tail]=a[tail]-min(t,a[tail]);
		if(a[head]==0) head++;
		if(a[tail]==0) tail--;
	}
	printf("%lld",ans);
	//cout<<ans;
	return 0;
}
