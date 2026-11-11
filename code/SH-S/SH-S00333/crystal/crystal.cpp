#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1,need;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);//ÉýÐò
	int id=1,res=1,mm=m;
	for(int i=2;i<=n;i++){
		mm=mm-res*(a[i]-a[i-1]);
		res++;
		while(mm<0) mm+=a[i]-a[id],id++,res--;
		ans=max(ans,res);
	}
//	for(int i=2;i<=n;i++){
//		int res=1;
//		long long mm=m;
//		for(int j=i-1;j>0;j--){
//			mm=mm-a[i]+a[j];
//			if(mm<0) {
//				la_id=j+1,la_res=res
//				break;
//			}
//			res++;
//		}
//		ans=max(ans,res);
//	}		cout<<res<<' '<<mm<<'\n';
	printf("%d",ans);
	return 0;
}
