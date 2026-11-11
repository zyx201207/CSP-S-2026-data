#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
vector<int>v1,v2;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k,sta=-1,ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
//	for(int i=0;i<=31;i++){
//		int sum=0;
//		for(int j=1;j<=n;j++){
//			int now=(a[j]>>i);
//			if(now&1ll)sum++;
//		}
//		if(sum>=k)printf("%lld %lld\n",i,(1ll<<i));
//	}
//	printf("----%lld\n",(1ll<<18)-1);
	for(int i=31;i>=0;i--){
		int sum=0;
		if(sta==-1){
			v2.clear();
			for(int j=1;j<=n;j++){
				int now=(a[j]>>i);
				if(now&1ll){
					v2.push_back(a[j]);
					sum++;
				}
			}
			if(sum>=k){
				sta=i;
				ans+=(1ll<<i);
				v1.clear();
				for(auto j:v2){
					v1.push_back(j);
				}
			}
		}
		else {
			v2.clear();
			for(auto j:v1){
				int now=(j>>i);
				if(now&1ll){
					sum++;
					v2.push_back(j);
				}
			}
			if(sum>=k){
				sta=i;
				ans+=(1ll<<i);
				v1.clear();
				for(auto j:v2){
					v1.push_back(j);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
