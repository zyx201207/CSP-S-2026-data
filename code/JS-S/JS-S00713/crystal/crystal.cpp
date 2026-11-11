#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005];
ll sum=0,x=1e18,cnt=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m,st,o;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum+=m;
    ll avr=sum/n;
    for(int i=1;i<=n;i++){
        if(a[i]>avr) b[i]=a[i]-avr;
        else b[i]=avr-a[i];
        x=min(x,b[i]);
    }
    for(int i=1;i<=n;i++){
        if(b[i]==x){
           st=a[i];
           o=i;
        }
    }
    for(int i=o-1;i>0;i--){
       if(st-a[i]<=m){
          m-=(st-a[i]);
          a[i]=st;
       }
       else break;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==st) cnt++;
    }
    cout<<cnt;
    return 0;
}
