#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],b[200005],sum;
char c[200005],c1[200005],c2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)sum+=a[i];
	ll cnt1=0,cnt2=0,i1=0,i2=n+1,ans=0,cnt=0;
	while(i1<i2-2){
		if(cnt1<cnt2||(cnt1==cnt2&&a[i1+1]<a[i2-1])){
			i1++;
			if(cnt1+a[i1]<=cnt2){
				b[++cnt]=a[i1];
				c1[cnt]=c[i1];
				c2[cnt]=c[i2];
			}
			else{
				b[++cnt]=cnt2-cnt1;
				c1[cnt]=c[i1];
				c2[cnt]=c[i2];
			}
			cnt1+=a[i1];
		}
		else{
			i2--;
			if(cnt2+a[i2]<=cnt1){
				b[++cnt]=a[i2];
				c1[cnt]=c[i2];
				c2[cnt]=c[i1];
			}
			else{
				b[++cnt]=cnt1-cnt2;
				c1[cnt]=c[i2];
				c2[cnt]=c[i1];
			}
			cnt2+=a[i2];
		}
	}
	if(cnt1>cnt2){
		b[++cnt]=cnt1-cnt2;
		c1[cnt]=c[i1+1];
		c2[cnt]=c[i1];
	}
	else{
		b[++cnt]=cnt2-cnt1;
		c1[cnt]=c[i1+1];
		c2[cnt]=c[i2];
	}
	for(int i=1;i<=cnt;i++){
		if(c1[i]!=c2[i])ans+=b[i];
	}
	cout<<ans;
	return 0;
}
/*哪个给佬出的，T2就这么难？？？？？？？
CCF have no egg！！！
十年OI一场空，不开long long见祖宗
*/