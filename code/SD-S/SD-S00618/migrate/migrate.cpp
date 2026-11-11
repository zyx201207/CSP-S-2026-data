#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
} 
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) x=-x,putchar('-');
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
int a[N],l[N],r[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=qr,T=qr;
	while(T--){
		int n=qr,d=qr;
		for(int i=1;i<=n;i++) a[i]=qr;
		if(n<=3){
			qwe(0);
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			bool flag=false;
			flag|=a[n]-a[i]>d;
			flag|=a[i]-a[1]>d;
			cnt+=!flag;
		}
		int ans=0;
		if(cnt==2){
			for(int l=1,r=1;l<=n&&r<=n;l++){
				while(r<=n&&a[r]-a[l]<=d) r++;
				ans+=l*(n-r+1);
			}
			qwe(ans);
		}
		else qwe(0);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
