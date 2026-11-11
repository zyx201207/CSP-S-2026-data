#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+10,M=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

ll read(){
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

int c,T;
ll n,m;
ll a[N],cha[N];
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==11||c==12){
		while(T--){
			n=read(),m=read();
			for(int i=1;i<=n;i++){
				a[i]=read();
				cha[i]=a[i]-a[i-1];
			}
			ll d=cha[2];
			if(d<<1>m||a[n]-a[1]<m)printf("0\n");
			else{
				int ans=m/d*2-1;
				ans=n-ans;
				printf("%d\n",ans);
			}
		}
		return 0;
	}
	while(T--){
		n=read(),m=read();
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			cha[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			int j;
			for(j=i+1;j<=n;j++){
				if(a[j]-a[i]>m)break;
			}
			ll cnt=0;
			for(int k=i;k>1;k--){
				if(cha[k]>m)break;
				cnt+=cha[k];
				if(cnt>m){
					ans++;
					break;
				}
			}
			cnt=0;
			for(int k=j+1;k<=n;k++){
				if(cha[k]>m)break;
				cnt+=cha[k];
				if(cnt>m){
					ans++;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

