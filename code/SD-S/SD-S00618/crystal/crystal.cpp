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
int a[N];
queue<int>q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=qr,m=qr;
	for(int i=1;i<=n;i++) a[i]=qr;
	sort(a+1,a+n+1);
	int ans=0,tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=q.size()*(a[i]-a[i-1]);
		while(tmp>m){
			tmp-=a[i]-q.front();
			q.pop();
		}
		q.push(a[i]);
		ans=max(ans,(int)q.size());
	}
	qwe(ans);
	return 0;
}
