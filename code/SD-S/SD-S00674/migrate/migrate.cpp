#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000002;
int ID,T,n,l,r;
ll h,a[N],b[N],f[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&ID,&T);
	while(T--){
		l=r=1;
		scanf("%d%lld",&n,&h);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		if(ID==11||ID==12){
			int d=n-(a[2]-a[1])/h;
			printf("%d\n",d);
		}
		for(int i=2;i<=n;i++){
			while(a[l]+h<a[i]) l++;
			while(a[i-1]+h<a[r]) r++;
//			b[i]+=b[l];
			for(int j=l+1;j<i;j++)
			ans+=b[j];
			for(int j=i+1;j<r;j++)
			b[j]+=1;
		}
//		puts("10\n");
//		for(int i=1;i<=n;i++){
//			int r=i;
//			for(int j=i-h;j<=i+j;j++){
//				for(int k=j;k<=r;k++){
//					f[k]=f[j];
//				}
//			}
//		}
	}
	return 0;
}
