#include<bits/stdc++.h>
using namespace std;

long long a[555555]={0};
vector<long long>v;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    long long n=0,m=0;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",a[i]);
    }

    long long ans=0;
    for(long long i=1;i<=n;i++){
        v.clear();
        long long r=0;
        for(long long j=i;j<=n;j++){
                long long fc=0;
            for(long long k=0;k>=r;k++){
                if(v[k]==a[j]){
                    fc=k;
                }
            }
            if(fc){
                r=v[fc];
            }
            else{
                v.push_back(a[j]);
                r++;
            }
        }
        bool flag=false;
        for(long long j=0;j<r;j++){
            if(v[j]==i){
                flag=true;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

