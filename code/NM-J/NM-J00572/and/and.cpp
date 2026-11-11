#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    long long a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+0,a+n);
    for(long long i=1;i<=m;i++){
        b[i-1]=a[n-i];
    }
    ans=b[0];
    for(long long i=1;i<m;i++){
        ans&=b[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
