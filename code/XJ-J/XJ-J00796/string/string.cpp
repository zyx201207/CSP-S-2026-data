#include<bits/stdc++.h>
using namespace std;
long long n,l[200010],r[200010],a[200010],s[200010],len=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf("%lld %c",&a[i],&c);
		len+=n;
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
		s[i]=c;
	}
	long long left=1,right=n;
	while(1){
		if(a[left]<a[right]){
			if(s[left]!=s[right]){
				ans+=a[left];
			} 
			a[right]-=a[left],left++;
		}
		if(a[left]>a[right]){
			if(s[left]!=s[right]){
				ans+=a[right];
			} 
			a[left]-=a[right],right--;
		}
		if(a[left]==a[right]){
			if(s[left]!=s[right]){
				ans+=a[right];
			} 
			left++,right--;
		}
		if(left>=right)break;
	}
	printf("%lld",ans);
	return 0;
}
