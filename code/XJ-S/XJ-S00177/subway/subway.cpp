#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,zhan,shu,ans,w[500005],s[505][25],t[505][50005],f[505][50005];
//f数组存每条地铁线 ,t为各个线路的站的站厅到站台的距离,s为存储每个站台被几号线经过 
string a;
long long int fun(long long int x,long long int y,long long int sum,long long int xian)//从站台a到b的从站台到站厅的距离的最小值 
{
	long long int i,j;
	if(x==y)
	  return t[xian][y];
	for(i=1;i<=s[x][0];i++)//几号线 
	{
		for(j=1;j<=f[s[x][i]][0];j++)//几号线到第几站 
		{
			//累加从这站到下站的路程，并递归 
			//当站f[s[x][i]][j]
			if(f[s[x][i]][j]!=x)
			  sum+=t[s[x][i]][x]+fun(f[s[x][i]][j],y,sum,s[x][i]);
			if(sum<ans)
			  ans=sum;
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int i,x,y,b,k,len;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	  cin>>w[i];
	
	k=0;
	while(getline(cin,a))
	{
		len=a.size();
		++k;//路线编号 
		b=-1;
		shu=-1;
		for(i=0;i<len;i++)
		{
			if(a[i]!=' ')
			  zhan=(zhan*10+(a[i]-'0'));
			if(a[i]==' ')
			{
				if(shu==0)
				  f[k][++b]=zhan;//输入为k 
				else
				  if(shu%2==1)//输入为经过的地铁站 
				  {
				    f[k][++b]=zhan;
				    //记录这个站台有的路线编号
				    s[f[k][b]][0]++;
				    s[f[k][b]][s[zhan][0]]=k;
				  }
				else//输入为这一站的站厅到站台的时间 
				  t[k][f[k][b]]=zhan;
				
				
				zhan=0;
			}
		}
		if(shu<=1)//如果只输入了两个数，是测试 
		{
			x=f[k][0];
			y=f[k][1];
			k--;
			ans=INT_MAX;
			cout<<fun(x,y,0,s[x][1])+w[x]+w[y]<<endl;
			//cout<<w[x]+w[y]<<endl;
			break;
		}
	}
	
	while(q--)
	{
	  cin>>x>>y;
	  ans=INT_MAX;
	  cout<<fun(x,y,0,s[x][1])+w[x]+w[y]<<endl;
	  //cout<<fun(x,y,0,s[x][1])<<endl;
	}
	return 0;
} 
/*
通过c可以知道是哪个性质从而打表，特判？ 
地铁口->站厅->站台
最终答案先算出两站中换成所有的地铁站的所有从站台到站厅时间的最小和，最后加上两个地铁站到地铁口的距离 

fun(起始站,终点站,距离,几号线)
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
