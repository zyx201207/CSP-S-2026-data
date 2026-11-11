#include<bits/stdc++.h>
using namespace std;
struct jg{
	long long zhi;
	long long cha;
};
jg a[5000005],c[5000005];
long long m,n;
long long q,jcs=0,ans;
bool ffz(jg x,jg y){
	return x.zhi<y.zhi;
}
bool ffc(jg x,jg y){
	return x.cha<y.cha;
}
bool ffzs(jg x,jg y){
	return x.zhi>y.zhi;
}
long long js;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	js=m;
	jcs=m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
		c[i].zhi=a[i].zhi;
	}
	sort(a+1,a+n+1,ffz);
	//
	if(n/2*2==n) q=n/2;
	else q=n/2+1;
	for(int i=1;i<=n;i++){
		a[i].cha=a[q].zhi-a[i].zhi;
		if(a[i].cha<0) a[i].cha=-a[i].cha;
	}
	//
	sort(a+1,a+n+1,ffc);
	//
	long long j;
	for(j=2;js>0;j++){
		js-=a[j].cha;
	}
	sort(a+1,a+j,ffzs);
	for(int i=1;i<=n;i++){
		c[i].cha=a[1].zhi-a[i].zhi;
		if(c[i].cha<0) c[i].cha=-c[i].cha;
	}
	sort(c+1,c+1+j,ffc);
	//终止条件问题 
	for(ans=1;jcs>0;ans++){
		jcs-=c[ans].cha;
	}
	if(jcs<0) ans--;
	//
	if(n==1) ans=2;
	cout<<ans-1;
	return 0;
}
