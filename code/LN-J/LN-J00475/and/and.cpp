#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5;
int m,n,a[maxn];
bool cmp(int a,int b)
{
    int ca=0,cb=0;
    while(a)ca+=a%2,a/=2;
    while(b)cb+=b%2,b/=2;
    return ca<cb;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    long long  ans=a[n];
    for(int i=1;i<m;i++)ans&=a[n-i];
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
