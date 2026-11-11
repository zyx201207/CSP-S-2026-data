#include<bits/stdc++.h>
using namespace std;
long long t1,c,n,m,d,q,k,line=0,w[550],p[550][550],p2[550][550],l;
long long t[550][550],flag;
int str[2005],des[2005],sta[550];
void pass(int a,int b)
{
  int i,j;
  for(i=1;i<=a;i++)
  {
      for(j=i+1;j<=a;j++)
      {
          p2[sta[i]][sta[j]]=b;
          p2[sta[j]][sta[i]]=b;
      }
  }
}
void pp(int a)
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			p[i][j]=p2[i][j];
		}
	}
}
int dfs(int tar,int lin,int tt,int esn)
{
    int i;
    if(tar==esn)
    {
		cout<<"W0W"<<tt+t[tar][lin]<<endl;
        return tt+t[tar][lin];
        flag=1;
    }
    else
    {
            for(i=1;i<=n;i++)
            {
                if(p[tar][i]!=0)
                {
                    if(lin!=p[tar][i])
                    {
						k++;
                        l=lin;
                        lin=p[tar][i];
                        p[tar][i]=0;
                        cout<<i<<" "<<lin<<" "<<tt+t[tar][l]+t[tar][lin]<<endl;
                        dfs(i,lin,tt+t[tar][l]+t[tar][lin],esn);
						p[tar][i]=lin;
                    }
                }
            }
    }
}
int main()
{
  int i,j;
  cin>>c>>n>>m>>d>>q;
  for(i=1;i<=m;i++)
  {
      cin>>w[i];
  }
  for(i=1;i<=n;i++)
  {
      cin>>k;
      for(j=1;j<=k;j++)
      {
          cin>>sta[j];
          cin>>t[sta[j]][i];
      }
      pass(k,i);
  }
  for(i=1;i<=q;i++)
  {
	  pp(i);
      cin>>str[i]>>des[i];
      int f=dfs(str[i],line,w[str[i]]+w[des[i]],des[i]);
      cout<<f<<endl;
      for(j=1;j<=m;j++)
      {
		  for(int l=1;l<=m;l++)
		  {
			  cout<<p[j][l];
		 }
			  
	}
	
  }
  return 0;
}
