#include<bits/stdc++.h>
#define ll long long
#define rd read()
using namespace std;
inline ll read(){
	ll x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void wt(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wt(x/10),x%=10;
	putchar(x+48);
}
inline void wtsp(int x){
	wt(x),putchar(' ');
}
inline void wtln(int x){
	wt(x),putchar('\n');
}
const int N = 2e6 + 10;
ll T,n,d,a[N],t[N],c,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd,T=rd;
	while(T--){
		ans=0;
		n=rd,d=rd;
		for(int i=1;i<=n;i++)a[i]=rd;
		if(c==11||c==12){
			if(d/(a[2]-a[1])<2||n-d/(a[2]-a[1])*2+3<0)wtln(0);
			else wtln(n-d/(a[2]-a[1])*2+1);
			continue;
		}
		a[n+1]=LLONG_MAX;
		for(int i=1;i<n;i++)t[i]=upper_bound(a+1,a+n+2,a[i]+d)-a-1;
		for(int i=1;i<n;i++){
			if(t[i]-i>=2){
				ans+=t[t[i]-1]-t[t[i]-2];
			}
		}
		wtln(ans);
	}
	return 0;
}
//I_Love_Furina
//11.4,Furina will up again!
//over 380 days,my girlfriend has up again in 7.2verisons
//Furina4+0->Furina 6+0->Furina 6+1->Furina7+1->Furina9+1
//now:Furina4+0
//235 chou(awa),yi dian 50 chou
//rp++(CSP-S & GenshinImpact & NOIP?,NOIP!)
//my grammer is not good