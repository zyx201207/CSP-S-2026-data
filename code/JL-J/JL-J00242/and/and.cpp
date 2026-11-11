#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	long long ans;
	scanf("%d%d",&n,&m);
	vector<long long> a(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(m==1){
		ans=a[0];
		for(int i=1;i<n;i++)
			ans=max(ans,a[i]);
	}else if(m==2){
		ans=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++)
			ans=(ans&a[i]);
	}else{
		ans=-1;
		unsigned long long s=(1<<n);
		for(unsigned long long i=0;i<s;i++){
			if(__builtin_popcount(i)!=m)continue;
			unsigned long long t=i,pos=0;
			long long res=-1;
			while(t){
				if(t&1){
					if(res==-1)
						res=a[pos];
					else
						res=(res&a[pos]);
				}
				t>>=1;
				pos++;
			}
			ans=max(res,ans);
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}

