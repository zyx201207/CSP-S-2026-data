#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+5;
ll a[N];
char c[N];
ll ans,k;
ll cnth,cntt;
ll n;
ll h,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        k+=a[i];
    }
    h=1,t=n;
    while(cntt<=k/2&&cnth<=k/2&&h<=t){
        if(c[t]!=c[h]){
            ans+=min(a[h],a[t]);
            if(a[h]>a[t]){
                cntt+=a[t];
                a[h]-=a[t];
                cnth+=a[t];
                t--;
            }
            else if(a[h]<a[t]){
                cnth+=a[h];
                a[t]-=a[h];
                cntt+=a[h];
                h++;
            }
            else if(a[h]==a[t]){
                cntt+=a[t];
                cnth+=a[h];
                t--,h++;
            }
        }
        else{
            if(a[h]>a[t]){
                cntt+=a[t];
                a[h]-=a[t];
                cnth+=a[t];
                t--;
            }
            else if(a[h]<a[t]){
                cnth+=a[h];
                a[t]-=a[h];
                cntt+=a[h];
                h++;
            }
            else{
                cntt+=a[t];
                cnth+=a[h];
                t--,h++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
3
2 a
2 b
1 c
*/
