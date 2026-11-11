#include<bits/stdc++.h>
using namespace std;
int a[200005];
int X[200005],Y[200005];
int res[200005],res2[200005];
int n,m;
int And(int x,int y)
{
    int num=0;
    int cntx=0,cnty=0;
    while(x>0){
        X[++cntx]=x%2;
        x/=2;
    }
    while(y>0){
        Y[++cnty]=y%2;
        y/=2;
    }
    int m=max(cntx,cnty);
    for(int i=0;i<m;i++)
    {
        res[i]=X[i+1]&&Y[i+1];
    }
    for(int i=m-1;i>=0;i--)
    {
        res2[i]=res[m-1-i];
        num+=pow(2,i)*res2[i];
    }
    return num;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int A=-1;
    while(m)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i==j)continue;
                A=max(A,And(a[i],a[j]));
            }
        }
        m--;
    }
    cout<<A;
    return 0;
}
