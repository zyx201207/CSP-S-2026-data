#include<bits/stdc++.h> 
using namespace std;
struct node{
	//int o[1000005];v 
	int u,x,h,g;
}b[5005];
int c,t,n,d,p,w,z,ans;
queue<int> q;
//bool v[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>d;
		p=i+1;
		for(int j=1;j<=n;j++)
		{
			cin>>b[j].x;
		}
		for(int j=1;j<=n;j++)
		{
			for(int y=1;y<=n;y++)
			{
				b[y].u=0;
				
				b[y].h=0;
			}
			q.push(b[j].x);
			z=0;
			for(int y=1;y<=n;y++)
			{
				b[y].u=(b[y].x-1)/2+1;
			}
			while(!q.empty())
			{
		
				z++;
				//v[j]=true;
				w=q.front();
				q.pop();
				for(int y=1;y<=n;y++)
				{
				    //if(b[y].x-w>=-d )
				    //{
				    	//q.push(b[y].x);
				    	//if(z==b[y].u)
				    	//{//
						
				    	    //q.push(b[y].x);
				    	    //b[y].h++;
				        //}
				    	//b[y].g=-1;
				    	//v[y]=true;
					//}
					if(b[y].x-w<=d)
					{
						q.push(b[y].x);
						if(z==b[y].u)
						{
							b[y].h++;
						}
						//b[y].g=1;
						//v[y]=true;
					}
				}
			}
			for(int y=1;y<=n;y++)
			{
				if(b[y].h==2) 
				    ans++;
			}
		}
		cout<<ans<<endl;
	}
}
