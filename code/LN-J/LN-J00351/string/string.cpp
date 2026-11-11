#include<bits/stdc++.h>
using namespace std;
struct cs
{
    int a;
    string s;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0;
    cin>>n;
    string z;
    cs b[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].a>>b[i].s;
        for(int j=1;j<=b[i].a;j++)
        z+=b[i].s;
    }
    if(z.size()%2==1)
    {
        int midle1=(z.size()+1)/2;
        for(int i=1;i<=z.size()/2;i++)
        {
            if(z[midle1+i-1]!=z[midle1-i-1])
                cnt++;
        }
    }
    else
    {
        int midle2=(z.size()+1)/2;
        for(int i=1;i<z.size()/2;i++)
        {
            if(z[midle2+i-1]!=z[midle2-i])
                cnt++;
        }
    }
    cout<<cnt;



    return 0;
}
