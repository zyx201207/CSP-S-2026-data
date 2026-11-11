#include<bits/stdc++.h>
#define ll long long
#define N (int)(5e5+5)
using namespace std;
ll a[N];int q[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	int l=1,r=0,s=0,ans=0;
	for(int i=1;i<=n;i++){
		q[++r]=i;s+=a[i];
		while(l<=r&&a[q[r]]*(r-l+1)-s>m){
			s-=a[q[l++]];
		}
		if(l<=r)ans=max(ans,r-l+1);
	}printf("%d",ans);
	return 0;
}//1e12*5e5=5e17<ll
