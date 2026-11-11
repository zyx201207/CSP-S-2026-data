#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool flag = 1;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    stable_sort(a+1,a+n+1);
    for(int i = 2;i < n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            flag = 0;
            break;
        }
    }
    //cout<<flag<<'\n';
    if(flag==1){
        if(a[n]==n){
            long long ans = (sqrt(1+8*m)+1)/2;
            cout<<ans;
            return 0;
        }
        long long d = a[n]-a[n-1];
        long long ans = (d+sqrt(d*d+8*m))/(2*d);
        cout<<ans;
        return 0;
    }

    /*for(int i = 1;i <= n;i++){
        cout<<a[i]<<' ';
    }*/
    //cout<<'\n';
    for(int l = 1,r = 1;r < n;r++){
        long long d = 0;
        for(int j = l;j <= r;j++){
            d += a[r+1]-a[j];
        }
        //cout<<l<<' '<<r<<' '<<d<<'\n';
        if(d>m)l++;
        else ans = max(ans,r-l+1);
    }
    //int l = 1,r = n;
   /* while(r<n){
        long long d = 0;
        for(int i = l;i <= r;i++){
            d+=a[r+1]-a[i];
        }
        if(d<=m){
            ans = max(ans,r-l+1);
            r++;
        }
        else l++;
    }*/
    cout<<ans;
    return 0;
}
