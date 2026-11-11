#include <bits/stdc++.h>
using namespace std;
int n,an;
long long m,a[500010],s[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1,j=1;j<=n;){
        long long k=a[j]*(j-i+1)-s[j]+s[i-1];
        if(k<=m){
            an=max(an,j-i+1);
            j++;
        }
        else i++;
        if(i>j)j++;
    }
    cout<<an<<endl;
    return 0;
}
