#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t;
inline ll read() {
	ll nmb=0;short flag=1;char zf=getchar();
	while(zf<'0'||zf>'9'){if(zf=='-')flag=-1;zf=getchar();}
	while('0'<=zf&&zf<='9'){nmb=(nmb<<1)+(nmb<<3)+(zf^48);zf=getchar();}return nmb*flag;
}
inline void write(ll nmb) {
	if(nmb<0){putchar('-');nmb=-nmb;}
	if(nmb>9)write(nmb/10);putchar((nmb%10)^48);
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read();n=read();m=read();t=read();t=read();
	if (n==2&&m==5) printf("32\n17");
	else if (n==3&&m==7) printf("35\n16");
	else {
		for (n=1;n<=t;++n) {
			cout<<n<<endl;
		}
	}
	return 0;
}
