#include<bits/stdc++.h>
using namespace std;
long long a[200005],t[35],b[35]={1};
bool f[35][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=30;i++){
		b[i]=b[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long z=a[i],j=1;
		while(z){
			t[j]+=z%2;
			f[j][i]=z%2;
			z/=2;
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			if(t[j]<m&&f[j][i]){
				a[i]-=b[j-1];
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++){
		swap(a[i],a[n-i+1]);
	}
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		for(int j=1;j<=30;j++){
			if(ans/b[j-1]%2==1&&a[i]/b[j-1]%2==0){
				ans-=b[j-1];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

