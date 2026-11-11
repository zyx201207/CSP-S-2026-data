#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[500005],need[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ans = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    long long mid=0;
    if(n%2==0)
        mid = a[n/2];
    else
        mid = a[(n/2)+1];
    for(int i=1;i<=n;i++)
        need[i]=mid - a[i];
    for(int i=n;i>=1;i--){
        if(need[i]<0)
            continue;
        else{
            if(m>=need[i]){
                ans++;
                m -= need[i];
            }
        }
    }
    cout << ans;
    return 0;
}
