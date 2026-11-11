#include<bits/stdc++.h>
using namespace std;
long long ans,a[200010],c[200010];
long long n,x,y;
char b[200010],d[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i]=a[i];
        d[i]=b[i];
    }
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    x=1;
    y=1;
    while(x<=n&&y<=n){
        if(b[x]==d[y]){
            if(a[x]<c[y]){
                c[y]-=a[x];
                ++x;
            }
            else {
                a[x]-=c[y];
                ++y;
            }
        }
        else {
            if(a[x]<c[y]){
                ans+=a[x];
                c[y]-=a[x];
                ++x;
            }
            else {
                ans+=c[y];
                a[x]-=c[y];
                ++y;
            }
        }
    }
    cout<<ans/2;
    return 0;
}
