#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=a[1];
    for(long long i=2;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    long long maxx=1;
    long long u=1;
    for(long long i=2;i<=n;i++){
        long long o=0;
        long long k=i*a[i]-b[i];
        if(k<=m){
            o=i;
        }
        else{
            break;
        }
        maxx=max(maxx,o);
    }
    long long p=maxx+2;
    for(long long i=p;i<=n;i++){
        if((i-u)*a[i]-b[i]+b[u]<=m){
            maxx=max(maxx,i-u);
        }
        else{
            u++;
        }
    }
    cout<<maxx;
    return 0;
}
