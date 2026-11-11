//T1 - crystal
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5e5 + 5;
int n,ans;
long long m,a[N],d[N],d_s1[N],d_s2[N];
inline long long maxx(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		d_s1[i]=d_s1[i+1]+d[i];
	}
	for(int i=n-1;i>=1;i--){
		d_s2[i]=d_s2[i+1]+d_s1[i];
	}
//	printf("d : ");
//	for(int i=1;i<=n-1;i++){
//		printf("%lld ",d[i]);
//	}
//	printf("\n");
//	printf("d_s1 : ");
//	for(int i=1;i<=n-1;i++){
//		printf("%lld ",d_s1[i]);
//	}
//	printf("\n");
//	printf("d_s2 : ");
//	for(int i=1;i<=n-1;i++){
//		printf("%lld ",d_s2[i]);
//	}
//	printf("\n");
	ans=0;
	for(int i=1;i<=n;i++){
		if(i==4){
			i=4;
		}
		int l=1,r=i,mid,res=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(d_s2[mid]-d_s2[i]-d_s1[i]*(i-mid)<=m){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=maxx(ans,i-res+1);
//		printf("%d : %d\n",i,i-res+1);
	}
	printf("%d\n",ans);
//	int ans2=0;
//	for(int i=1;i<=n;i++){
//		long long cst=0;
//		for(int j=i;j>=1;j--){
//			cst+=a[i]-a[j];
//			if(cst<=m){
//				ans2=maxx(ans2,i-j+1);
//			}
//		}
//	}
//	if(ans2!=ans){
//		printf("WA %d\n",ans2);
//	}
	fclose(stdin);fclose(stdout); 
	return 0;
}
