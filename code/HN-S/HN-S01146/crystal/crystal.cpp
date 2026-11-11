#include<bits/stdc++.h>
#define kks 500005
#define ll long long
using namespace std;
int n;
ll m,a[kks],f[kks],s=1;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) f[i]=a[i]-a[i-1];
	int mid=a[(n+1)/2];
	for(int i=1;i<=(n+1)/2;i++){
		m-= mid-a[i]; a[i]=mid;
	}
	for(int i=2;i<=n;i++)
	  if(a[i]==a[i-1]) s++;
	printf("%lld",s);
	return 0;
}
