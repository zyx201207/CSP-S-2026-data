#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
long long count_one(long long n){
    long long sum=0;
    while(n){
        int j=(n&1);
        sum+=j;
        n>>=1;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<(1<<(n));i++){
        if(count_one(i)!=m){
            continue;
        }
        bool sum=false;
        long long qqq=0;
        for(long long j=0;j<n;j++){
            if(i&(1<<j)){
                if(!sum){
                    qqq=a[j];
                    sum=true;
                }else{
                    qqq=(qqq&a[j]);
                }
            }
        }
        ma=max(qqq,ma);
    }
    cout<<ma;
    return 0;
}
