#include<bits/stdc++.h>
using namespace std;
int n,m,a[21001],zd=-1;
int yu(int x,int y)
{
    int h=0;
    string x1,y1;
    while(x!=0)
    {
        x1+=char(x%2);
        x=x/2;
    }
    while(y!=0)
    {
        y1+=char(y%2);
        y=y/2;
    }
    string jg="";
    for(int i=0;i<max(x1.size(),y1.size());i++)
    {
        if(x1[i]!=y1[i]) jg+='0';
        else jg+='1';
    }
    int da=0;
    for(int i=0;i<jg.size();i++)
        da+=(pow(2,i)*(jg[i]-'0'));
    return da;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<yu(n,m);

    return 0;
}
