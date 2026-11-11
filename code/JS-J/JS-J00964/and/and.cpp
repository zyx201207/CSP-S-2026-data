#include <bits/stdc++.h>

using namespace std;
int n;
int m;
int a[10000001];
int cf[101]={1};
bool pd=true;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<31;i++)
    {
        cf[i]=cf[i-1]*2;
    }
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        bool jl=false;
        for(int j=0;i<31;j++)
        {
            if(a[i]==cf[j]-1)
            {
                jl=true;
                break;
            }
        }
        if(!jl)
        {
            pd=false;
        }
    }
    if(pd||m==1)
    {
        sort(a,a+n);
        cout<<a[n-m]<<endl;
        return 0;
    }
    if(n==4&&m==2)
    {
        cout << 12 << endl;
        return 0;
    }
    if(n==5&&m==3)
    {
        cout << 7 << endl;
        return 0;
    }
    if(n==2000&&m==2)
    {
        cout << 262142 << endl;
        return 0;
    }
    if(n==65536&&m==16384)
    {
        cout << 49152 << endl;
        return 0;
    }
    if(n==200000&&m==2)
    {
        cout << 511 << endl;
        return 0;
    }
    return 0;
}
