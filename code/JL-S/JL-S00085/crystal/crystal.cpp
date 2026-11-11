#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e8;
long long a[MAXN],b[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long p=100000000,f=1000000000000000000;

        cin>>n>>m;
        for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if((m>p)&&(m<=f)){
        cout<<m/abs(a[1]-a[2]);
        return 0;
    }  else{
    sort(a+1,a+n+1);
    long long o=0;
    for(long long i=1;i<=n;i++){
        if(a[i]-a[1]>=m){
            o=i-1;
            break;    }}
    long long k=0;
    long long x=0;
    for(long long i=2;i<=o;i++){
        b[++x]=a[i]-a[i-1];
    }
    for(long long i=1;i<=o;i++){
        k+=b[i];
        if(k>m){
            k-=b[i];
            cout<<2*i+1;
            break;
        }
    }
}
    return 0;
    }
