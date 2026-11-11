#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
