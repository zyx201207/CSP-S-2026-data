#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum=0,ans=0;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]&a[i+1]>=sum)
        {
            sum=a[i]&a[i+1];
        }
    }
    cout<<sum;
    return 0;
}
