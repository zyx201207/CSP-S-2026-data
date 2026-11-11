#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],l,r,flag,cnt,p3[2000005],p2[2000005],cnt2,cnt3,p,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>=4&&a[i]-a[i-3]>d){
				flag=true;
				for(int j=i-2;j<=i-1;j++){
					if(a[i]-a[j]>d||a[j]-a[i-4]>d){
						flag=false;
					}
				}
				p2[++cnt2]=i-3;
			}
			if(i>=5&&a[i]-a[i-4]>d){
				flag=true;
				for(int j=i-3;j<=i-1;j++){
					if(a[i]-a[j]>d||a[j]-a[i-4]>d){
						flag=false;
					}
				}
				p3[++cnt3]=i-4;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				p=p3[lower_bound(p3+1,p3+cnt3+1,i)-p3];
				if(!p||p+4>j){
					p=p2[lower_bound(p2+1,p2+cnt2+1,i)-p2];
					if(p&&p+3<=j){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
