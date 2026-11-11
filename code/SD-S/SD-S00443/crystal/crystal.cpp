#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll n,m,a[N],d[N],s[N]={0},ans=0;
bool b[N]={0};
ll a2[N];
bool cmp(int x,int y) {
	if(x>0&&y>0)
		return x<y;
	if(x>0&&y<0)
		return x>y;
	if(x<0&&y>0)
		return x<y;
	if(x<0&&y<0)
		return -x>-y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool t=1;
	scanf("%d",&a[1]);
	for(ll i=2;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]!=a[1])
			t=0;
	}
	if(t==1) {
		printf("%d\n",n);
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<n;i++) {
		d[i]=a[i+1]-a[i];
	}
	for(ll i=2;i<=n;i++) {
		s[i]=s[i-1]+(i-1)*d[i-1];
	}
	for(ll i=n;i>=1;i--) {
		for(int j=i-1;j>=1;j--) {
			if(s[i]-s[j]>m)
				break;
			else {
				ans=max(ans,i-j+1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
