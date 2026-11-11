#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> sj(500005,0);
vector<long long> jl1(1,0);
vector<long long> jl2(1,0);
bool check(long long x)
{
    if((jl1[x-1]*(x-1))-jl2[x-2]<=m)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long ch=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>sj[i];
    }
    sort(sj.begin(),sj.begin()+n+1);
    for(long long i=1;i<n;i++)
    {
        ch=ch+(sj[i+1]-sj[i]);
        jl1.push_back(ch);
    }
    jl1[0]=0;
    long long ch2=0;
    for(long long i=1;i<n;i++)
    {
        ch2+=jl1[i];
        jl2.push_back(ch2);
    }
    long long out=0;
    long long l=1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            if(mid>out)
            {
                out=mid;
            }
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<out;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
