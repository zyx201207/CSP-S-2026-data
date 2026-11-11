#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long l,r,md;
vector<long long> a;
long long sum;
bool check(){
    sum = 0;
    for(long long i = 1;i<md;i++){
        sum+=a[md]-a[i];
    }
    for(long long i = 2; sum>m&&i+md<=n+1 ;i++){
        sum = sum-(a[i+md-1] - a[i-1])+(a[md+i]-a[md+i-1])*md;
    }
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    a.resize(n+3);
    for(int i = 1;i<=n;i++){
        scanf("%lld",a.begin()+i);
    }
    sort(a.begin()+1,a.begin()+n+1);
    a[n+1] = a[n];
    l = 1;r = n;
    while(l<r){
        md = l+(r-l)/2 +1;
        if(check()){
            l = md;
        }
        else{
            r = md-1;
        }
    }
    printf("%lld",l);
    return 0;
}
