#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define il inline
#define re register
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=2e6+6;
int t,n,m,a[N],nt[N],f[N][2][3][2];
il int get_(re int x,re int y,re int* st)
{
	if(x>=y)return 0;
	re int qwq=0;
	for(re int i=0;i<3;i++){
		if(!st[i])return qwq;
		if(a[y]-a[x-i]>m)return qwq;
		qwq+=st[i];
	}
	return qwq;
}
il int get(re int x,re int st1,re int st2,re int st3)
{
//	if(x==8&&st1==1&&st2==2&&st3==0)
//		printf("%lld,%lld,%lld,%lld------\n",x,st1,st2,st3);
	if(x==nt[x])return 0;st3++;
	re int st[3]={st3,st2,st1};
	re int y=nt[x],z3=get_(x,y,st);
//		printf("%lld,%lld,%lld,%lld--------\n",y,z3,z3,z3);
	if(z3>2)return 0;
	re int z2=get_(x,y-1,st);
	if(z2>2)z2=2;
	re int z1=get_(x,y-2,st);
	if(z1>1)z1=1;
	return f[y][z1][z2][z3-1];
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(),t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;i++)
			a[i]=read();
		re int it=n;
		for(re int i=n;i;i--){
			while(a[it]-a[i]>m)it--;
			nt[i]=it;
		}
//		for(re int i=1;i<=n;i++)
//			printf("%lld ",nt[i]);
//		printf("\n");
		for(re int i=1;i<=n;i++)
			for(re int st1=0;st1<2;st1++)
				for(re int st2=0;st2<3;st2++)
					for(re int st3=0;st3<2;st3++)
						f[i][st1][st2][st3]=0;
		re int awa=0;
		for(re int i=n;i;i--){
//			if(nt[i]>i+2)awa+=f[nt[i]][1][1][0],printf("%lld,%lld,%lld,%lld,%lld\n",nt[i],1,1,0,f[nt[i]][1][1][0]);
//			else if(nt[i]==i+2)awa+=f[nt[i]][0][1][0],printf("%lld,%lld,%lld,%lld,%lld\n",nt[i],0,1,0,f[nt[i]][0][1][0]);
//			else if(nt[i]==i+1)awa+=f[nt[i]][0][0][0],printf("%lld,%lld,%lld,%lld,%lld\n",nt[i],0,0,0,f[nt[i]][0][0][0]);
			if(nt[i]>i+2)awa+=f[nt[i]][1][1][0];
			else if(nt[i]==i+2)awa+=f[nt[i]][0][1][0];
			else if(nt[i]==i+1)awa+=f[nt[i]][0][0][0];
			for(re int st1=0;st1<2;st1++)
				for(re int st2=0;st2<3;st2++)
					for(re int st3=0;st3<2;st3++)
						if(st3)
							f[i][st1][st2][st3]=get(i,st1,st2,st3)+nt[i]-max(i,nt[i-1]);
						else{
							if(st2&1){
								f[i][st1][st2][st3]=get(i,st1,st2,st3);
								if(nt[i-1]>i)f[i][st1][st2][st3]+=nt[i-1]-max(i,nt[i-2]);
							}
							else
								f[i][st1][st2][st3]=get(i,st1,st2,st3);
//							if(i==8&&st1==1&&st2==2&&st3==0)
//								printf("%lld----\n",f[i][st1][st2][st3]);
						}
		}
//		printf("%lld-----------\n",f[8][1][2][0]);
//		for(re int i=1;i<=n;i++)
//			for(re int st1=0;st1<2;st1++)
//				for(re int st2=0;st2<3;st2++)
//					for(re int st3=0;st3<2;st3++)
//						printf("%lld,%lld,%lld,%lld : %lld\n",i,st1,st2,st3,f[i][st1][st2][st3]);
		printf("%lld\n",awa);
	}
	return 0;
}
