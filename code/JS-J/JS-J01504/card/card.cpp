#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long c[500005];
long long d[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q=n;
    int cnt=0;
    while(q--){
        for(int i=0;i<n;i++){
            d[i]=a[i];
        }
        for(int i=cnt;i<n;i++){
            b[d[i]]++;
            for(int j=cnt;j<i;j++){
                if(d[j]==d[i]){
                    for(int z=j+1;z<=i;z++){
                        b[d[z]]--;
                        d[z]=0;
                    }
                }
            }
            for(int i=1;i<=m;i++){
            }
        }

        for(int i=1;i<=m;i++){
            c[i]+=b[i];
            b[i]=0;
        }
        cnt++;
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
