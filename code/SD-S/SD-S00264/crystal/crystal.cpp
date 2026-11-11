#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int maxn=5e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int a[maxn],d[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	n=read(),m=read();
	int flag1=1,flag2=1;
	int cha=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==2) cha=a[2]-a[1];
		if(i>2){
			if(a[i]-a[i-1]!=cha) flag2=0;
		}
		if(a[i]!=i) flag1=0;
	}
	if(flag2){
		int cnt=1,val=cha;
		for(int i=n;i>=1;i--){
			if(m>=val){
				m-=val;
				cnt++;
				val+=cha;
			}
			else break;
		}
		write(cnt);
		return 0;
	}
	if(flag1){
		int cnt=1,val=1;
		for(int i=n;i>=1;i--){
			if(m>=val){
				m-=val;
				cnt++;
				val++;
			}
			else break;
		}
		write(cnt);
		return 0;
	}
	sort(a+1,a+n+1);
	int maxx=-1;
	int tmp=m;
	for(int i=1;i<n;i++){
		d[i]=a[n]-a[i];
	}
	int val=0;
	for(int i=n-1;i>=1;i--){
		int tmp=m;
		int cnt=1;
		int tot=i;
		while(tmp>=(d[tot]-val)&&tot>=1){
			tmp-=(d[tot]-val);
			tot--;
			cnt++;
		}
		val=d[i];
		maxx=max(maxx,cnt);
	}
	write(maxx);
	return 0;
}
/*
10 27
-5 -3 1 3 8 14 17 20 21 27

32 30 26 24 19 13 10 7 6 
26 24 20 18 13 7 4 1    -6
25 23 19 17 12 6 3    -7
22 20 16 13 9 3     -10

*/
/*
我是傻逼吗
*/


/*
完了，全完了。我们将一切都赌在了CSP-S2026的胜利，而这一切都随着评测机上堆积如山的WA化为了泡影。我们别无他法，只能静静咽下苦果，看着其他选手自顾自地庆祝“伟大胜利”
*/ 
