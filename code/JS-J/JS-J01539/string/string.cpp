#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s,k1,k2;
struct A{
    long long num;
    char o;
}f[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        cin>>f[i].num>>f[i].o;
    }
    long long i=1;
    long long j=n;
    while(i<j){
        long long mn=min(f[i].num,f[j].num);
        if(f[i].o!=f[j].o){
            ans+=mn;
        }
        f[i].num-=mn;
        f[j].num-=mn;
        if(f[i].num==0){
            i++;
        }
        if(f[j].num==0){
            j--;
        }
    }
    printf("%lld",ans);
    return 0;
}
