#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=5e5+5;
int n,ans;
ll m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	int l=1,r=1,sum=0;
	for(int r=1;r<=n;r++){
		sum=sum+(a[r]-a[r-1])*(r-l);
		while(l<r&&sum>m){
			sum=sum-a[r]+a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
