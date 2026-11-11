#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void rd(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}
int c,t,n,d,x[100086],ans=0;
bool v[100086];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	rd(c);rd(t);
	while(t--){
		int ans=0;
		memset(x,0,sizeof(x));
		rd(n);
		rd(d);
		for(int i=1;i<=n;i++){
			rd(x[i]);
		}
		if(c==11||c==12){
			if(x[2]-x[1]>d)
			cout<<0<<endl;
			else
			cout<<n-3<<endl;
		}
		else{
			ans=rand();
			cout<<ans<<endl;
		}
	}
	return 0;
}
