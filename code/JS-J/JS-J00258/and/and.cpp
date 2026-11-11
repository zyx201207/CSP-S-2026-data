#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long num[40];
long long tmp;
long long a[200005][40];
long long x;
long long ans;
long long p;
long long k;
long long j;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&tmp);
        x=pow(2,31);
        for(j=1;j<=32;j++){
            a[i][j]=tmp/x;
            num[j]+=a[i][j];
            tmp%=x;
            x/=2;
        }
    }
    x=pow(2,32);
    for(long long i=1;i<=32;i++){
        x/=2;
        if(num[i]>=m){
            ans+=x;
            for(k=1;k<=n;k++){
                if(a[k][i]==0){
                    for(p=1;p<=32;p++){
                        num[p]-=a[k][p];
                        a[k][p]=0;
                    }
                }
            }
        }

    }
    cout<<ans;
    return 0;
}
