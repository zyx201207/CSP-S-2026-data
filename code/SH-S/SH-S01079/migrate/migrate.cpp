#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e6+9;

int c,t;
ll n,d;
ll x[maxn];
ll fl[maxn],fr[maxn]; //每个点产生的贡献 
ll ans=0;
int nS=0;
ll nl[maxn],nr[maxn];

void init()
{
	ans=0;
	nS=0;
	for(int i=1;i<=n;++i)
	{	fl[i]=1; fr[i]=1; }
	return ;
}

void solveA()
{
	int l=1;
	ll lst=0;
	for(int r=1;r<=n;++r)
	{
		while( l<r && x[r]-x[l]>d ) ++l; //要到得了 
		lst=l;
		if(lst==nl[nS]) //覆盖旧区间 
		{
			nr[nS]=r;
		}
		else //新区间
		{
			nl[++nS]=lst;
			nr[nS]=r;
		} 
	}
	
	int i=1;
	for(int j=2;j<=nS;++j) //处理区间 
	{
		while(i+1<j && nr[i]-nl[j]+1<2) //重叠<2不要 往右挪 若往右是自己就不挪
			++i;
		if(nr[i]-nl[j]+1==2)
		{
			ans+=(nl[i+1]-nl[i])*(nr[j]-nr[j-1]);
		}
	}
	
	printf("%lld\n",ans); 
	
	return ;
}

void solve()
{
	int l=1;
	ll lst=0;
	for(int r=1;r<=n;++r)
	{
		while( l<r && x[r]-x[l]>d ) ++l; //要到得了 
		lst=l;
		if(lst==nl[nS]) //覆盖旧区间 
		{
			nr[nS]=r;
		}
		else //新区间
		{
			nl[++nS]=lst;
			nr[nS]=r;
		} 
	}
	
	//for(int i=1;i<=nS;++i)
	//	printf("l= %lld | r= %lld\n",nl[i],nr[i]);
	
	int i=1,j=1;
	for(j=2;j<=nS;++j) //处理区间 
	{
		while(i+1<j && nr[i]-nl[j]+1<1) //重叠<2不要 往右挪 若往右是自己就不挪
			++i;
		if(nr[i]-nl[j]+1==1)
		{
			for(int k=nl[i];k<nl[i+1];++k)
				fl[nr[i]]+=fl[k];
		}
	}
	i=n,j=n;
	for(i=n-1;i>=1;--i) //处理区间 
	{
		while(i<j-1 && nr[i]-nl[j]+1<1) //重叠<2不要 往右挪 若往右是自己就不挪
			--j;
		if(nr[i]-nl[j]+1==1)
		{
			for(int k=nr[j];k>nr[j-1];--k)
				fr[nr[i]]+=fr[k];
		}
	}
		
	i=1;
	for(j=2;j<=nS;++j) //处理区间 
	{
		while(i+1<j && nr[i]-nl[j]+1<2) //重叠<2不要 往右挪 若往右是自己就不挪
			++i;
		if(nr[i]-nl[j]+1==2)
		{
			//ans+=(nl[i+1]-nl[i]+fl[nl[i]]-1)*(nr[j]-nr[j-1]+fr[nr[j]]-1);
			ans+=(nl[i+1]-nl[i]+fl[nl[i]]-1)*(nr[j]-nr[j-1]);
		}
	}
	
	printf("%lld\n",ans); 
	
	return ;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",&x[i]);
		
		for(int i=n;i>=1;--i)
			x[i]-=x[1];
			
		init();
		
		//for(int i=1;i<=n;++i)
		//	printf("%lld ",x[i]);
		//printf("\n");
			
		if(c==13 || c==14)
			printf("0\n");	
		else if(c==11 || c==12)
			solveA();
		else solve();
	}
	
	return 0;
}
