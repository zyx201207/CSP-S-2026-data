#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b,c,sum=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        b=i;
        c=1;
        for(int j=m;j>=0;){
            if(j>=a[b]-a[b-1]&&b>1){
                j=j-a[b]+a[b-1];
                b--;
                c++;
            }else break;
        }
        if(c>sum)sum=c;
    }
    cout << sum;
    return 0;
}
