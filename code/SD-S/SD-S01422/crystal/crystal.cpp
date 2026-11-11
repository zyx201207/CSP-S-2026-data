#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int n;
long long m;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=1;
	long long xu=0;
	int l=1,r=2;
	while(r<=n){
		xu+=(a[r]-a[r-1])*(r-l);
		while(l<r&&xu>m){
			xu-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	printf("%d",ans);
	return 0;
}

