#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c\n",&a[i],&c[i]);
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		int WillUse=min(a[l],a[r]);
		if(c[l]==c[r]){
			a[l]=a[l]-WillUse;
			a[r]=a[r]-WillUse;
		}
		else{
			ans=ans+WillUse;
			a[l]=a[l]-WillUse;
			a[r]=a[r]-WillUse;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
