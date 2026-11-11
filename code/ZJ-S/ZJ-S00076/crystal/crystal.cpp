#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N];
inline int read(){
	char c=getchar();
	int num=0,op=1;
	while(c<'0'||c>'9'){
		if(c=='-')
			op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		num=num*10+c-'0',c=getchar();
	return num*op;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1,greater<int>());
	int now=1,leftm=m,ans=0;
	for(int i=1;i<=n;i++){
//		cout<<now<<' '<<leftm<<endl;
		while(now<n&&a[i]-a[now+1]<=leftm)
			now++,leftm-=a[i]-a[now];
//		cout<<now<<endl;
		ans=max(ans,now-i+1);
//		cout<<a[i]<<' '<<a[i+1]<<endl;
		leftm+=(a[i]-a[i+1])*(now-i);
//		cout<<leftm<<endl;
	}
	cout<<ans<<endl;
}
/*
Oct31==Dec25?
*/
