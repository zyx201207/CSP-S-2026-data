#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[2000050],q[2000050],cs,n,d,sum;
void poi(int aa,int bb,int bs,int yu)
{
    if(aa>=bb)
    {
        if(yu<=cs)
            sum++;
            return;
    }
  //  cout<<"dfss";
    if(bs>=q[aa+1])
    {
        bs-=q[aa+1];
        aa+=1;
        poi(aa,bb,bs,yu);
        aa-=1;
        bs+=q[aa+1];
    }
    //cout<<"fdh"<<yu<<endl;
    if(bs<d)
    {
        bs=d;
        yu++;
        poi(aa,bb,bs,yu);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int qq=1;qq<=t;qq++)
    {
        sum=0;int sc=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        for(int i=2;i<=n;i++)
            q[i]=p[i]-p[i-1];
        for(int i=1;i<=n;i++)
        {

            for(int o=i+3;o<=n;o++)
            {
                sum=0;
                int m=d;
                cs=0;
                for(int k=i+1;k<=o;k++)
                {

                    cs++;
                    if(m-q[k]>=0)
                        cs--,m-=q[k];
                    else m=d;
                    if(q[k]>d)
                    {
                        cs=-1;
                        break;
                    }//cout<<"dsfjhhfd"<<cs<<" "<<m<<" "<<q[k]<<endl;
                }
                if(cs==-1)
                {
                    break;
                }
                //cout<<cs<<endl;
                poi(i,o,d,0);
                if(sum==2)
                    sc++;
            }
        }
        //cout<<cs<<endl<<sum<<endl;
        cout<<sc<<endl;
    }
}
