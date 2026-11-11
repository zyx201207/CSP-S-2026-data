#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[300010];
long long c[300010];
long long p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        p=0;
        for(long long j=i;j<=n;j++){
            p+=1;
            b[p]=a[j];
            for(long long k=1;k<=p;k++){
                if(b[k]==a[j]){
                    p=k;
                    break;
                }
            }
        }
        for(long long j=1;j<=p;j++){
            c[b[j]]+=1;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
