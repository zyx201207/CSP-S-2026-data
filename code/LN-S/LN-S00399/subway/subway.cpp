#include <bits/stdc++.h>
using namespace std;
long long ert,a1,b1,amax,r;
vector<long long>su;
vector<long long>b;
int j1,k1;
int j2,k2;
int mina=INT_MAX;int sum=0;
struct c
{
    int a2;
    long long t1;
    long long idx;
};
void dfs(c a[a1][b1+1],int en,int st)
{
    if(j1==j2)
    {
        su.push_back(sum);
        sum=0;
    }
    else{

    }
}
int main()
{
    cin>>ert>>a1>>b1>>amax>>r;
    c a[a1][b1+1]={};
    for(int i=0;i<b1;i++)
    {
        int tyu;
        cin>>tyu;
        b.push_back(tyu);
    }
    for(int i=1;i<=a1;i++)
    {
        int k;
        cin>>k;
        a[i][1].a2=k
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j+1].a2>>a[i][j+1].t1;
        }
    }
    for(int i=1;i<=r;i++)
    {

        int st,en;
        cin>>st>>en;
        sum+=b[st-1];sum+=b[en-1];
        if(st!=en)
        {
            int y=0
            for(int j=1;j<=a1;j++)
            {
                for(int k=2;k<=a[j][1].a2+1;j++)
                {
                    if(a[j][k].a2==en)
                    {
                        sum+=a[j][k].t1;
                        j1=j;
                        k1=k;
                        y++;
                    }
                    else if(a[j][k].a2==st)
                    {
                        sum+=a[j][k].t1;
                        k2=k;
                        j2=j;
                        y++;
                    }
                    if(y==2) break;
                }
                if(y==2) break;
            }
            dfs(a,en,st);
        }
        else
        {
            su.push_back(0);
        }
    }
    cout<<sum;
    return 0;
}
