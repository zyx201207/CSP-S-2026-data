#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],len,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
	long long l=1,r=n;
	while(l<r-1){
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		} 
	}
	if(l==r-1&&c[l]!=c[r])ans+=min(a[l],a[r]);
	cout<<ans;
	return 0;
}
