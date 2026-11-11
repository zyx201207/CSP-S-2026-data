#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n[N],d[N],x[N][N];
int main()
{
    long long c,t,l=0,r=0;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {

        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++)
        {
            cin>>x[i][j];
        }
    }
    for(int i=0;i<t;i++)
    {

        for(int j=1;j<=(n[i]-d[i]+2)*(n[i]-d[i])/2;j++)
        {
            l=j*d[i]-1;
            if(l<=x[0][n[i]-1]-x[0][0]){
                r+=n[i]-d[i]+2;
            }
        }
        cout<<r;
        r=0;
        l=0;

    }
}
