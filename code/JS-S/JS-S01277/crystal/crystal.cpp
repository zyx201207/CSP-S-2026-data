#include<bits/stdc++.h>
using namespace std;
long long a[500005]{};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,l=1,r=1,cnt=0,num=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(r<n&&l<=r){
        while(l<=r&&r<n&&cnt+(num+1)*(a[r+1]-a[r])<=m){
            r++;
            num++;
            cnt+=num*(a[r]-a[r-1]);
        }
        cnt-=(a[r]-a[l]);
        l++;
        r++;
        cnt+=num*(a[r]-a[r-1]);
        while(cnt>m&&l<=r&&r<n){
            cnt-=(a[r]-a[l]);
            l++;
            r++;
            cnt+=num*(a[r]-a[r-1]);
        }
    }
    cout<<num+1;
    return 0;
}
