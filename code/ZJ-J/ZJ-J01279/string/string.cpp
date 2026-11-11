#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
int n,l=1,r;
char c[N];
LL a[N],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	r=n;
	for(int i=1;i<=n;i++)
		scanf("%d %c",a+i,c+i);
	if(n==1){
		printf("%d",0);
		return 0;
	}
	for(;l<r;){
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
