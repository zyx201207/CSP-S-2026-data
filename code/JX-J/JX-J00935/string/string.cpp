#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
char c[N];
ll ans=0;
int main()
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
       }
    int i=1,j=n;
    while(i<j){
        if(c[i]!=c[j]){
            if(j-i==1){
                if(c[i]!=c[j]){
                    ans+=min(a[i],a[j]);
                    cout<<ans;
                    return 0;
                   }
                break;
               }
            if(a[i]>a[j]){
                a[i]-=a[j];
                ans+=a[j];
                --j;
               }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                ans+=a[i];
                ++i;
               }
            else{
                ans+=a[i];
                ++i,--j;
               }
           }
        else{
            if(a[i]==a[j]) ++i,--j;
            else if(a[i]>a[j]){
                a[i]-=a[j];
                --j;
               }
            else{
                a[j]-=a[i];
                ++i;
               }
           }
       }
    cout<<ans;
    return 0;
  }
