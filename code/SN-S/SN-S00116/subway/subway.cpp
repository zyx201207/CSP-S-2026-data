#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,kou[500001],mi[501][501],mm,mmm,e[501],ans,xx,yy,zz;

struct node{
	int x,j;
}kk,kkk;

vector<node> j[500001];

vector<int > g[501];

int aaa(int x,int f,int z)
{
	if(e[x]==1){
		return 0;
	}
	e[x]=1;
	if(x==kkk.x )
	{
		ans=z;
		return z;
	}
	int ann=2000000001;
	for(int i=0;i<g[x].size();i++)
	{
		int yu=g[x][i];
		int middd=aaa(yu,x,z+mi[x][yu]);
		if(middd!=0)
		ann=min(ann,middd);
	}
	
	return ann;
}




signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)
	{
		cin>>kou[i];
		for(int o=1;o<=m;o++){
			mi[o][i]=2000000001;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>xx;
		for(int u=1;u<=xx;u++){
			cin>>yy>>zz;
			kk.x=i;
			kk.j=zz;
			j[yy].push_back(kk);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(j[i].size()>1){
			for(int u=0;u<j[i].size();u++)
			{
				for(int o=u+1;o<j[i].size();o++)
				{
					kk=j[i][u];
					kkk=j[i][o];
					mi[kk.x ][kkk.x ]=min(kk.j+kkk.j,mi[kk.x ][kkk.x ]);
					mi[kkk.x ][kk.x]=min(kk.j+kkk.j,mi[kkk.x ][kk.x]);
					g[kk.x ].push_back(kkk.x);
					g[kkk.x].push_back(kk.x);
				}
			}
		}
	}

	for(int i=1;i<=q;i++){
		cin>>xx>>yy;
		for(int i=0;i<j[xx].size();i++)
		{
			for(int o=0;o<j[yy].size();o++){
				kk=j[xx][i];
				kkk=j[yy][o];
				memset(e,0,sizeof(e));
				int midddd=aaa(kk.x ,0,0);
				if(midddd!=0)
				ans=min((midddd+kk.j+kkk.j) ,ans);
			}
		}
		cout<<ans+kou[xx]+kou[yy]<<endl;;
	}
	
	
	return 0;
}



