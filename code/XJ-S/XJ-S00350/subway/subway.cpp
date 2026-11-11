#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k[500],a[500][1000],t[500][1000],in,out;
int w[1000];
struct Str{
	int ai,aj,tj;
}st[500][1000];
bool vis[500][1000];
int daoda=0;
int ans=INT_MAX;

void bfs(int ai,int aj,int tj,int step,int in,int out)
{
	//cout<<step<<endl;
	//cout<<"1";
	if(st[ai][aj].tj==0&&st[ai][aj].aj==0&&vis[ai][aj+1]!=1)
	{
		vis[ai][aj]=1;
		bfs(ai,aj+1,st[ai][aj+1].tj,step,in,out);
	}
	if(vis[ai][aj]==1)
	{
		return;
	}
	if(daoda==1)
	{
		return;
	}
	queue<Str> q;
	Str qu;
	qu.ai=ai;
	qu.aj=aj;
	qu.tj=st[ai][aj].tj;
	q.push(qu);
	while(daoda==0)
	{
		//cout<<"3";
		vis[ai][aj]=1;
		if(step>ans)
		{
			//cout<<"!"<<endl;
			return;
		}
		if(aj==out)
		{
			//cout<<"?"<<endl;
			int ans_=step+w[out]+st[ai][aj].tj;
			if(ans_<ans)
			{
				ans=ans_;
				//cout<<ans;
				daoda=1;
			}
			return;
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(st[i][j].aj==aj&&vis[i][j]!=1)
				{
					flag=0;
					//cout<<st[i][j].ai<<" "<<st[i][j].aj<<" "<<st[i][j].tj<<endl;
					bfs(i,j,st[i][j].tj,step+st[ai][aj].tj,in,out);
				}
			}
		}
		if(flag&&vis[ai][aj+1]!=1)
		{
			vis[ai][aj]=1;
			//cout<<st[ai][aj+1].ai<<" "<<st[ai][aj+1].aj<<" "<<st[ai][aj+1].tj<<endl;
			bfs(ai,aj+1,st[ai][aj+1].tj,step+st[ai][aj].tj,in,out);
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int I=0;I<=c;I++)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>k[i];
			for(int j=0;j<k[i];j++)
			{
				int a,b;
				cin>>a>>b;
				st[i][a].ai=i;
				st[i][a].aj=a;
				st[i][a].tj=b;
			}
		}
		for(int i=0;i<q;i++)
		{
			cin>>in>>out;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(st[i][j].aj==in)
					{
						bfs(i,j,st[i][j].tj,w[in],in,out);
						cout<<ans<<"\n";
						daoda=0;
						ans=INT_MAX;
						for(int z=0;z<n;z++)
						{
							for(int x=0;x<m;x++)
							{
								vis[z][x]=0;
							}
						}
						//cout<<"2";
						
					}
				}
			}
		}
		if(c!=0)
		{
			for(int i=0;i<500;i++)
			{
				k[i]=0;
				w[i]=0;
				for(int j=0;j<1000;j++)
				{
					a[i][j]=0;
					t[i][j]=0;
					st[i][j].ai=0;
					st[i][j].aj=0;
					st[i][j].tj=0;
					vis[i][j]=0;
				}
			}
		}
	}

	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
