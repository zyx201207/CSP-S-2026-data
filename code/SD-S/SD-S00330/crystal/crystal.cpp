#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
int ans=0;
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
bool cmp(int x,int y){
	return x>y;
}
bool check(int k){
	int o=m,sum=0;
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		if(r==0){
			b[++r]=a[i];
			sum+=a[i];
			continue;
		}
		int y=b[l];
		if(a[i]!=y){
			int h=(y-a[i]);
			while(h>o&&l<=r){
				sum-=b[l],l++;
				o=m-((r-l+1)*b[l]-sum);
				y=b[l],h=(y-a[i]);
			}
		}
		b[++r]=a[i];
		sum+=a[i];
		o-=(y-a[i]);
		if(r-l+1>=k) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	stable_sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
