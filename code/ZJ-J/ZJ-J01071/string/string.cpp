#include<iostream>
using namespace std;
const int N=2e5+100;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				l++;r--;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}