#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    for(int i=0;i<t;i++)
    {
        cin>>n>>d;
        int zuobiao[500005]={0};
        int juli[500005];
        for(int j=1;j<=n;j++)
        {
            cin>>zuobiao[j];
            int zenjia=0;
            if(zuobiao[1]<1)
            {
                zenjia=1-zuobiao[1];
            }
            zuobiao[j]+=zenjia;
            juli[j]=zuobiao[j]-zuobiao[j-1];
        }
        int h=zuobiao[n]%d;
        if(h>=0&&zuobiao[n]/d<1)
        {
            cout<<zuobiao[n]/d+1;
        }
        else if(h>=0&&zuobiao[n]/d<=2)
        {
            cout<<zuobiao[n]/d;
        }
        else
        {
            cout<<0;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
