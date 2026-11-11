#include<bits/stdc++.h>
using namespace std;
int n;
long long b[500005],a[500005],m,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		long long l=0,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(b[i]-b[mid]-mid*(a[i]-a[mid])>m){
				l=mid+1;
			}else
				r=mid;}
		ans=max(ans,i-l);}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
