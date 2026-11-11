#include <bits/stdc++.h>

using namespace std;
long long n,m,a[100000],b[100000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    sort(b,b+n);
    int i=1,cnt=1,sum=0;
    while(m>cnt*b[i]){
        m-=cnt*b[i];
        cnt++;
        sum++;
        i++;
    }
    cout<<sum+1;
    return 0;
}
