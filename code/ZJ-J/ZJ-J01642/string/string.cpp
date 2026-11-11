#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld %c",&a[i],&s[i]);
	long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(s[l]!=s[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(s[l]!=s[r]) ans+=a[l];
			l++;
			r--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}