#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,ans,g,u,p,q,m,a[N],mi=2147483647,mx=-2147483647;
bool cmp(int k1,int k2){
	if (k1<k2) return false;
	return true;
}
int js(int k){
	int l=1,r=n;
	while (l+1!=r){
		int mid=(l+r)>>1;
		if (a[mid]>=k) l=mid;else r=mid;
	}
	int ans=m,cnt=0;
	for (int i=l;i>0;i--) if (a[i]==k) cnt++;else break;
	for (int i=r;i<=n;i++){
		ans-=k-a[i];
		if (ans<0) return cnt;
		else cnt++;
	}return cnt;
}bool pd(){
	int o=a[2]-a[1];
	if (n<5) return false;
	for (int i=2;i<=n;i++) if (a[i]-a[i-1]!=o) return false;
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n,cmp);
	if (pd()){
		u=a[1]-a[2];
		g=m;
		g/=u;
		p=sqrt(2*g);
		if (g*2<p*(p+1)) cout<<min(p,n);
		else cout<<min(p+1,n);
		return 0;
	} 
	for (int i=1;i<=n;i++){
		mi=min(mi,a[i]),mx=max(mx,a[i]);
	}
	for (int i=mi;i<=mx;i++) ans=max(ans,js(i));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
