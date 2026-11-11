#include<cstdio>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

