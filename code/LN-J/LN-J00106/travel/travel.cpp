#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,r1,r2;
    cin>>x1>>x2>>r1>>r2;
    int out[4]={0,0,0,0};
    string p1="",p2="";
    p1=x2[0]+x2[1];
    p2=r2[0]+r2[1];
    if(x1==r1)
    {
        out[0]=1;
        if(p1==p2)
        {
            out[1]=1;
            if('A'<=x2[2]&&'C'>=x2[2])
            {
                if('A'<=r2[2]&&'C'>=r2[2])
                {
                    out[2]=1;
                    if(abs(x2[2]-r2[2])==1)
                    {
                        out[3]=1;
                    }
                }
            }
            else if('D'<=x2[2]&&'F'>=x2[2])
            {
                if('D'<=r2[2]&&'F'>=r2[2])
                {
                    out[2]=1;
                    if(abs(x2[2]-r2[2])==1)
                    {
                        out[3]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        cout<<out[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
