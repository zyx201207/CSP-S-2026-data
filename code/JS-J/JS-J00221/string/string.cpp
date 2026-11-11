#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int x;
    char c;
    bool flag=true;
    long long cop=0;
    long long copp=0;
    long long mop=0;
    char r;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>c;
        if(i>1&&c!=r)
        {
            flag=false;
        }
        r=c;
        for(int j=1;j<=x;j++)
        {

            a[j+mop]=c;

        }
        mop+=x;
    }
    if(flag)
    {
        cout<<0;
        return 0;
    }
    cop=mop/2;
    for(int i=1;i<=cop;i++)
    {
        if(a[i]!=a[mop-i+1])
        {
            copp++;
        }
    }
    cout<<copp<<endl;
    return 0;
}
