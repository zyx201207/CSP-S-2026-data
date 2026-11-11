#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans1,ans,l,py;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[l-i+1]+py&&c[i]==c[l-i+1]){
			if(a[i]>a[l-i+1]+py)
				ans1+=a[i]-a[l-i+1]-py,py=a[i]-a[l-i+1]-py;
			if(a[i]<a[l-i+1]+py)
				ans1+=a[l-i+1]+py-a[i],py=a[l-i+1]+py-a[i];
		}
		if(c[i]!=c[l-i+1]&&a[i]==a[l-i+1]+py)
			ans1+=a[i],py=0;
		if(a[i]!=a[l-i+1]+py&&c[i]!=c[l-i+1]){
			ans1+=a[i];
			if(a[i]>a[l-i+1]+py)
				py=a[i]-a[l-i+1]-py;
			if(a[i]<a[l-i+1]+py)
				py=a[l-i+1]+py-a[i];
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]!=a[l-i+1]+py&&c[i]==c[l-i+1]){
			if(a[i]>a[l-i+1]+py)
				ans+=a[i]-a[l-i+1]-py,py=a[i]-a[l-i+1]-py;
			if(a[i]<a[l-i+1]+py)
				ans+=a[l-i+1]+py-a[i],py=a[l-i+1]+py-a[i];
		}
		if(c[i]!=c[l-i+1]&&a[i]==a[l-i+1]+py)
			ans+=a[i],py=0;
		if(a[i]!=a[l-i+1]+py&&c[i]!=c[l-i+1]){
			ans+=a[i];
			if(a[i]>a[l-i+1]+py)
				py=a[i]-a[l-i+1]-py;
			if(a[i]<a[l-i+1]+py)
				py=a[l-i+1]+py-a[i];
		}
	}
	ans=min(ans,ans1);
	printf("%d",ans);
}
