#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int b,c=1e9;
    for(int i=1;i<=n-1;i++){
        int s=c;
        c=min(c,a[i+1]-a[i]);
        if(c!=s) b=i;
    }
    int ans=1,d=0;
    if(b==1||((a[b+1]-a[b])<(a[b]-a[b-1])&&a[b+1]!=a[b])){
        for(int i=b;i<=n-1;i++){
            d+=ans*(a[i+1]-a[i]);
            if((m-d)>=0){
               ans++;
           }else{
                break;
            }
        }
    }else{
        for(int i=b;i>=1;i--){
            d+=ans*(a[i]-a[i-1]);
            if((m-d)>=0){
               ans++;
           }else{
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}