#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
bool cmp(int A,int B){
	return A>B;
}
int GetWeiShu(int x){
	int res=0;
	while(x>0){
		res++;
		x>>=1;
	}
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int WeiShuMax,WeiShuMin;
	do{
		sort(a+1,a+1+n,cmp);
		WeiShuMax=GetWeiShu(a[1]);
		WeiShuMin=GetWeiShu(a[m]);
		if(WeiShuMax>WeiShuMin){
			for(int i=1;i<=n;i++){
				if(a[i]>=(1<<WeiShuMin)){
					a[i]=a[i]-(1<<WeiShuMin);
				}
				else{
					break;
				}
			}
		}
	}while(WeiShuMax>WeiShuMin);
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	printf("%lld",ans);
	return 0;
}
