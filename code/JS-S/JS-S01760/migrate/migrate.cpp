#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12)
    {
        for(int z=0;z<t;z++)
        {
            int n,d;
            cin>>n>>d;
            int is[n];
            for(int i=0;i<n;i++)
            {
                cin>>is[i];
            }
            int derta=is[1]-is[0];
            int num=(d-d%derta)/derta+1;
            if(d<2*derta)
            {
                cout<<"0"<<endl;
                continue;
            }
            int cnt=0;
            for(int i=2*num;i<=n;i++)
            {
                cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    if(c==13||c==14)
    {
        for(int z=0;z<t;z++)
        {
            int n,d;
            cin>>n>>d;
            int is[n];
            for(int i=0;i<n;i++)
            {
                cin>>is[i];
            }
            int mid;
            for(int i=0;i<n;i++)
            {
                if(is[i]-is[0]<=d&&is[n-i]-is[i]<=d)
                {
                    mid=i;
                }
            }
            int cnt=0;
            for(int j=1;j<n-mid;j++)
            {
                int p;
                for(int i=0;i<n;i++)
                {
                    if(is[i]-is[0]<=d&&is[n-j]-is[i]<=d)
                    {
                        p=i;
                    }
                }
                for(int i=0;i<p;i++)
                {
                    if(is[p+1]-is[i]<=d&&is[p+2]-is[i]>d)
                    {
                        cnt++;
                    }
                }
            } 
            cout<<cnt<<endl;  
        }
    }
    return 0;
}