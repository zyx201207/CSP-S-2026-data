#include<bits/stdc++.h>
#include<chrono>
#define ms microseconds
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define N 5005
using namespace std;
using namespace chrono;
auto Star=system_clock::now();
auto GetTime(){return (double)(duration_cast<ms>(system_clock::now()-Star).count())*ms::period::num/ms::period::den;}
void PrintTime(){cout<<"Cost="<<GetTime()<<endl;}
ll read()
{
	ll t=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) t=t*10+ch-48,ch=getchar();
	return t*f;
}
int num1[N][N],ad[N],num2[N][N],cnt[N];
ll a[N],D;
int n,ans=0;
void fun(int st,int num[][5005])//zhengxiang
{
	int i,j,now=st;
	for(i=1;i<=n;i++) ad[i]=0,cnt[i]=0;
	while(now<n)
	{
		int pos1=upper_bound(a+1,a+1+n,D+a[now])-a;pos1=pos1-1;//zuiyou a[r]-a[now]<=D
		
		ad[now+1]++;ad[pos1+1]--;cnt[now+1]++;cnt[pos1+1]--;
//		printf("S=%d now=%d pos1=%d\n",st,now,pos1);
		if(now-1>=st)
		{
			int pos2=upper_bound(a+1,a+1+n,D+a[now-1])-a;pos2=pos2-1;
			ad[now+1]--;ad[pos2+1]++;cnt[now+1]++;cnt[pos2+1]--;
//			printf("pos2=%d \n",pos2);
		}
		if(pos1==now) break;//
		
		now=pos1;
	}
	for(i=1;i<=n;i++) ad[i]+=ad[i-1];
	for(i=1;i<=n;i++) cnt[i]+=cnt[i-1];
//	printf("cnt:");for(i=1;i<=n;i++) printf("%d ",cnt[i]);printf("\n");
	for(i=1;i<=n;i++) 
	{
//		cnt[i]+=cnt[i-1];
		if(cnt[i]==2) 
		{
			ans++;
//			printf("S=%d i=%d\n",st,i);
		}
	}
//	printf("ans=%d\n",ans);
//	for(i=st;i<=n;i++) num[st][i]+=ad[i];
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),i,j; int T=read();
	while(T--)
	{
		n=read(),D=read();
		ans=0;
		for(i=1;i<=n;i++) 
		{
			a[i]=read();
			for(j=1;j<=n;j++) num1[i][j]=num2[i][j]=0;
		}
		for(i=1;i<=n;i++) fun(i,num1);//cong i kaishi 
//		for(i=1;i<=n;i++) a[i]=-a[i];//duichen
//		for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);//daoxu
//		for(i=1;i<=n;i++) fun(i,num2);//cong i kaishi 
//		for(i=1;i<=n;i++)
//		{
//			for(j=1;j<=n;j++) printf("%d ",num1[i][j]);printf("\n");
//		}
//		for(i=1;i<=n;i++)
//		{
//			for(j=1;j<=n;j++) printf("%d ",num2[i][j]);printf("\n");
//		}
//		for(i=1;i<=n;i++)
//		{
//			for(j=i+1;j<=n;j++) 
////			if(num1[i][j]==1&&num2[n-j+1][n-i+1]==1&&(1ll*(a[j]-a[i])%D!=0)&&(a[j]-a[i]>D)) ans++;//daoxu
////			if(num1[i][j]==1&&(1ll*(a[j]-a[i])%D!=0)&&(a[j]-a[i]>D)) ans++;//daoxu
//		}
		printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);

}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
