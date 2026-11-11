#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[100005],d[500005],k[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ll n,m,cur,cnt,max=0,l=1,q;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	bool f;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]>m&&f)l++;
		else f=0;
	}for(int j=l+1;j<=n;j++){
		cnt=0;cur=0;q=m;
		for(int i=j;(i<=n)&&q>=0;i++){
			cur++;
			q-=cur*d[i];
			cnt++;
		}if(cnt>max)max=cnt;
	}printf("%lld",max);
	return 0;
}
