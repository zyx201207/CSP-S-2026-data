#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,T,n,k,U[N],V[N];
int siz[N],dep[N],is[N],xx,yy,sum;
int psiz,fa[N];
vector<int>R[N];
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
//void DFS1(int f,int u,int ct,int&ans)
//{
//	siz[u]=1;
//	int can=1;
//	for(int v:R[u])
//	{
//		if(v==ct)
//		{
//			//printf("cant\n"); 
//		}
//		if(v==f||v==ct) continue;
//		DFS1(u,v,ct,ans);
//		if(psiz&&siz[v]>psiz/2)
//			can=0;
//		siz[u]+=siz[v];
//	}
//	if(psiz&&psiz-siz[u]>psiz/2)
//		can=0;
//	if(can)
//	{
//		ans=u;
//		//printf("chenged\n");
//	}
//}
void DFS1(int f,int u,int ct,int&ans,int d)
{
	dep[u]=d,fa[u]=f;
	if(dep[ans]<dep[u])
		ans=u;
	for(int v:R[u])
	{
		if(v==f||v==ct) continue;
		DFS1(u,v,ct,ans,d+1);
	}
}
void DFS2(int f,int u,int ct,int d,int x)
{
	dep[u]=d,is[u]=0;
	int can=0;
	for(int v:R[u])
	{
		if(v==f||v==ct) continue;
		DFS2(u,v,ct,d+1,x);
		dep[u]=max(dep[u],dep[v]);
		if(is[v]) can=1;
	}
	if(dep[u]-d>=x||f==u||can)
		++sum,is[u]=1;
}
int check(int x)
{
	for(int i=1;i<n;i++)
	{
		xx=yy=0;
//		psiz=0;
//		DFS1(U[i],U[i],V[i],xx),
//		psiz=0;
//		DFS1(V[i],V[i],U[i],yy),
//		psiz=siz[U[i]];
//		DFS1(U[i],U[i],V[i],xx),
//		psiz=siz[V[i]];
//		DFS1(V[i],V[i],U[i],yy);
		int u=0,v=0,r1=0,r2=0;
		DFS1(U[i],U[i],V[i],u,1);
		DFS1(u,u,V[i],v,1);
	//	printf("%d %d %d\n",u,v,dep[v]/2);
		int manba=dep[v]/2;
		r1=v;
		while(manba--)
			r1=fa[r1];
		u=v=0;
		DFS1(V[i],V[i],U[i],u,1);
		DFS1(u,u,U[i],v,1);
		//printf("%d %d %d\n",u,v,dep[v]/2);
		manba=dep[v]/2;
		r2=v;
		while(manba--)
			r2=fa[r2];
		sum=0;
		DFS2(r1,r1,V[i],0,x),
		DFS2(r2,r2,U[i],0,x);
		
		//printf("edge:%d %d %d %d\n",U[i],V[i],r1,r2);
		//for(int j=1;j<=n;j++)
		//	printf("%d %d %d\n",j,dep[j],is[j]);
		//printf("%d\n",sum);
		if(sum<=k)
		{
			//printf("%d can solve\n",x);
			return 1;
		}
	}
	//printf("%d cant solve\n",x);
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		n=read(),k=read();
		for(int i=1;i<=n;i++)
			R[i].clear();
		for(int i=1;i<n;i++)
		{
			U[i]=read(),V[i]=read();
			R[U[i]].push_back(V[i]),
			R[V[i]].push_back(U[i]);
		}
		if(c>=11)
		{
			int m=n>>1;
			int ll=1,rr=n,anss=1;
			int num1=1;
			while(ll<=rr)
			{
				int mid=(ll+rr)>>1,can=0;
				for(int i=2;i<m;i++)
					if(max(i+2-2*mid,num1)+max(m-i+2-2*mid,num1)<=k)
					{can=1;break;}
				if(can) rr=mid-1,anss=mid;
				else ll=mid+1;
			}
			printf("%d\n",anss);
			continue; 
		}
		int l=1,r=n,ans=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			//printf("%d %d %d\n",l,r,mid);
			if(check(mid))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
