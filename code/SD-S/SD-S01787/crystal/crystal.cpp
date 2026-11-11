#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n,m,ans,sum,cnt,k=1;
vector<int> a;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	a.resize(n+1);
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a.begin()+1,a.end());
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		int x=(a[i]-a[i-1])*sum;
		while(cnt+x>m){
			cnt-=(a[i]-a[k]);
			sum--;
			k++;
		}
		cnt+=x;
		sum++;
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
