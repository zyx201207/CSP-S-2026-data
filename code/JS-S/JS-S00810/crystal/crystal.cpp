#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000;
int a[700005],p[700005];
signed main(){
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0;
    int s=1;
    p[0]=0,p[1]=a[1];
    for(int i=2;i<=n;i++){
        p[i]=p[i-1]+a[i];
        while(a[i]*(i-s)-p[i-1]+p[s-1]>m) s++;
        sum=max(sum,i-s+1);
        //cout<<s<<endl;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

