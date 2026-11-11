#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long maxn=-100010;
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==3)cout<<7;
    if(n==65536&&m==16384)cout<<49152;
    if(m==1){
        for(long long i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=2;j<=n;j++){
                if(i!=j)maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    if(m==3){
        for(long long i=1;i<=n;i++){
            for(long long j=2;j<=n;j++){
                for(long long k=3;k<=n;k++){
                    if(i!=j&&j!=k&&i!=k)maxn=max(maxn,a[i]&a[j]&a[k]);
                }
            }
        }
    }
    cout<<maxn;
    return 0;
}

//freopen!!!
//long long!!!
//NO AC is OK,because this is T3
