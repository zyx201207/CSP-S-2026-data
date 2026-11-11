#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long k,cnt1,n,m,ans,a[N],cnt_0[N];
bool ff,f[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	memset(f,0,sizeof(f));
	if(m==1){
		printf("%lld\n",a[1]);
	}
	for(int i=30;i>=0;i--){
		k=0,cnt1=0;
		memset(cnt_0,0,sizeof(cnt_0));
		if(!ff&&!((a[1]>>i)&1)){
			continue;
		}
		ff=1;
		for(int j=1;j<=n;j++){
			if(f[j]==0){
				if((a[j]>>i)&1==1){
					cnt1++;
				}
				else{
					cnt_0[++k]=j;
				}
			}
		}
		if(cnt1>=m){
			ans+=(1ull<<i);
			for(int i=1;i<=k;i++){
				f[cnt_0[i]]=1;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
