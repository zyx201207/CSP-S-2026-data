#include<bits/stdc++.h>
using namespace std;

long long n=0,d=0;
vector<long long>x;
bool f(long long z1,long long z2){
    return x[z1+1]-x[z1]<=d && x[z2]-x[z1+1]<=d && x[z2-1]-x[z1]<=d && x[z2]-x[z2-1]<=d;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=0;
    long long t=0;
    scanf("%d%lld",&c,&t);

    while(t--){
        n=0;
        d=0;
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++){
            long long xl=0;
            scanf("%lld",&xl);
            x.push_back(xl);
        }

        long long ans=0;
        for(long long i=1;i+3<=n;i++){
            if(f(i,i+3)){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
