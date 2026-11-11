#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int tot[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool complete[300005]={false};//end card num
        bool tong[300005]={false};//card on table
        int table[500005]={0},frt=1,tail=1;
        for(int j=i;j<=n;j++)
        {
            if(tong[a[j]]==false)
            {
                table[frt]=a[j];
                tong[a[j]]=true;
                frt++;
            }
            else
            {
                for(int k=tail;k<=frt;k++)
                {
                    if(a[k]==a[j])
                    {
                        frt=k+1;
                        tong[a[j]]=true;
                        table[frt]=0;
                        break;
                    }

                }
            }
        }
        for(int k=tail;k<=frt;k++)
        {
            //cout<<table[k]<<" ";
            complete[table[k]]=true;
        }
        //cout<<endl;
        for(int i=1;i<=m;i++)
        {
            if(complete[i]==true)
                tot[i]++;
        }
         //for(int i=1;i<=m;i++)
        //{
            //cout<<tot[i]<<" ";
    //}
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
        {
            cout<<tot[i]<<" ";
        }
    return 0;
}
