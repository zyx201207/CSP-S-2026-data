#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1000005];
long long b[1000005];
long long c[1000005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }

    for(long long i=1;i<=n;i++){

        for(long long j=i;j<=n;j++){
            for(long long k=1;k<j;k++){
                if(b[k]==a[j]){
                    for(long long l=k;l<j;l++){
                        b[l]=0;
                    }
                }
            }
            b[j]=a[j];
        }

        for(long long j=1;j<=n;j++){
            if(b[j]!=0){
                c[b[j]]+=1;
            }
        }

        for(long long j=1;j<=n;j++){
            b[j]=0;
        }


    }
    for(long long i=1;i<=m;i++){
        cout << c[i] << ' ';
    }
    return 0;
}
