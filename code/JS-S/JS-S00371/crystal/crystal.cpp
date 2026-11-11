#include <iostream>
#include<algorithm>
using namespace std;
int n,m,in[500010],a[2][500010][2]={0};

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
        a[1][i][0]=1;
        a[0][i][0]=1;
    }
    int out=abs(in[0]-in[1])*(n-1)*n/2;
    if(out<=m){cout<<n;return 0;}
    for(int i=n-1;i>0;i--){
        int out=abs(in[0]-in[1])*(i-1)*i/2;
        if(out<=m){cout<<i;return 0;}
    }


    /*for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(in[j-1]>in[j])
            {
                int y=in[j-1];
                in[j-1]=in[j];
                in[j]=y;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<j;k++)
            {
                a[i&1][j][1]=0;
                a[i&1][j][0]=0;
                if(((a[(i-1)&1][k][0]*(in[i]-in[i-1])+a[(i-1)&1][k][1]<a[i&1][j][0])||(a[i&1][j][0]==0))&&(a[(i-1)&1][k][0]*(in[i]-in[i-1])+a[(i-1)&1][k][1]<=m))
                {
                    a[i&1][j][0]=a[(i-1)&1][k][0]+1;
                    a[i&1][j][1]=a[(i-1)&1][k][0]*(in[i]-in[i-1])+a[(i-1)&1][k][1];
                }
            }
            if(a[i&1][j][1]==0)
            {
                a[i&1][j][0]=a[i&1][j-1][0];
                a[i&1][j][1]=a[i&1][j-1][1];
            }
        }
    }
    cout<<a[(n-1)&1][n-1][0];*/
    return 0;
}
