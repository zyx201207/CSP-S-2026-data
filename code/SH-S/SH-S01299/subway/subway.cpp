#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
int t[500][20];
int r[500];
int w[500000];
int se(int nx,int xx,int ny,int yy){
	if(xx>yy){
		swap(xx,yy);
		swap(nx,ny);
	}
	int ansx=0;
	bool ok=1;
	int j1=1,j2=1;
	while(1){
		int ans=0;
		for(int i=x+1;i<=y;i++)
		{
			for(int j=j1;j<=2*r[i-1]-1;j+=2){
				for(int g=j2;g<=2*r[i]-1;g+=2)
				{
					if(t[i-1][j]==t[i-1][g])
					{
						ok=0;
						ans++;
						j1=j;
						j2=g;
						ans+=t[i][j+1]+t[i][g+1];
						break;
					}
					if(!ok)break; 
				}
			if(!ok)break;
			if(ok)return ansx;
			}
		}
		ansx=max(ansx,ans);
	}
	return ansx;
}
int maa;
void dfs(int x,int y){
	vector<int>dy(n,0);
	vector<int>dx(n,0);
	int nx=0,ny=0;
	int xx=0,yy=0;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=2*r[i]-1;j+=2){
			if(t[i][j]==x){
				dx[i]=j;
				nx=j;
				xx=i;
			}
			if(t[i][j]==y){		
				dy[i]=j;
				ny=j;
				yy=i;
			}
			if(dx[i]>0&&dy[i]>0)maa=w[x]+w[y]+t[i][nx+1]+t[i][ny+1];
			if(nx&&ny)
			{
				maa=max(se(nx,xx,ny,yy),maa);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		r[i]=k;
		for(int j=1;j<=2*k;j++)
		{
			cin>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		dfs(x,y);
		cout<<maa<<endl;
		maa=0;
	}
	return 0;
}
