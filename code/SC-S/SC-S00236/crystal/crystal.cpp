#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,sum=0,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		sum+=b[i];
		d+=a[i];
	}
	d+=a[1];
	if(sum==0) {
		printf("%d",n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=(i-1)*b[i]+b[i-1];
		if(m>=a[i]) ans=i;
	}
		cout<<ans;
	return 0;
} 