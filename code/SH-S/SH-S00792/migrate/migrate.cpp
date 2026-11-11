#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
inline void read(T &s){
	int f=1;
	char ch=getchar();
	s=0;
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	s*=f;
}
int n,d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	read(c); read(T);
	if(1)
	{
		while(T--)
		{
			read(n); read(d);
			int t1,t2,t,x;
			read(t1); read(t2);
			for(int qwq,i=3;i<=n;++i)
				read(qwq);
			t=d/(t2-t1);
			x=2*t;
			if(t==0ll||t==1ll)
				printf("%lld\n",0);
			else
				printf("%lld\n",max(0ll,n-x+1));		
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
