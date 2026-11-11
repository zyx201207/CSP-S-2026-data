#include <cstdio>
#include <iostream>
#include <algorithm>

const int maxn=200005;

int a[maxn];
char c[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),std::cin>>c[i];
	
	long long ans=0;
	for(int i=1,j=n;i<=j;){
		if(a[i]==a[j]&&c[i]==c[j]) i++,j--;
		else if(c[i]==c[j]){
			int maxij=i,minij=j;
			if(a[j]>a[i]) maxij=j,minij=i;
			
			a[maxij]-=a[minij];
			if(minij==i) i++;
			else j--;
		}else{
			int maxij=i,minij=j;
			if(a[j]>a[i]) maxij=j,minij=i;
			
			ans+=a[minij];
			a[maxij]-=a[minij];
			if(minij==i) i++;
			else j--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
