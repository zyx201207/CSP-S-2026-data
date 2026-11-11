#include<bits/stdc++.h>
using namespace std;

int n,a[200010],l,r;
char c[200010];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char x;
		scanf("%d%c%c",&a[i],&x,&c[i]);
	}
	l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans=ans+0LL+a[l];
			}
			a[l]=a[r]=0;
			l++,r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans=ans+0LL+a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			if(c[l]!=c[r]){
				ans=ans+0LL+a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	printf("%lld",ans);
}