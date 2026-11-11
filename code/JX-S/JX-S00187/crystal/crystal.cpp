#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[500005];
long long m;
int n;
int anss=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long HG=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0;
    int l=0;
    for(int i=1;i<=n;i++)
    {
        l++;
        sum+=a[i];
        while(m<(l*a[i])-sum)
        {
            sum-=a[i-l+1];
            l--;
        }
        anss=max(anss,l);
    }
    cout<<anss<<endl;
    return 0;
}
