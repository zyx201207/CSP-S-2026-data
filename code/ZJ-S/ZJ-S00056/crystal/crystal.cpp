#include<bits/stdc++.h>
#define int long long

const int N=5e5+10;

using namespace std;

int T;

int n,m,ans;

int a[N];

int s[N];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

bool _chk(int i,int pos){
	int now=(i-pos+1)*a[i];
	int lst=s[i]-s[pos-1];
	if(now-lst<=m)return 1;
	return 0;
}

void _solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=1,R=i;
		while(L+10<=R){
			int mid=(L+R)>>1;
			if(_chk(i,mid))R=mid;
			else L=mid;
		}
		for(int j=L;j<=R;j++){
			if(_chk(i,j)){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	T=1;
	while(T--)_solve();
	return 0;
}