#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005],ans[300005];
long long v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m; cin>> n >> m;
    for(long long i=1;i<=n;i++) cin>> a[i];
    bool l=1;
    for(long long i=1;i<=n-1;i++){
        if(a[i]>a[i+1]){
          l=0;
          break;
        }
    }
    if(l==1){
        long long jz=1;
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            if(a[i]!=jz){
                jz++;
                cout<< cnt << ' ';
            }
            cnt++;
        }
        cout<< cnt;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n-i+1;j++){
            b[j]=a[i+j-1];
        }
        long long k=1;
        for(long long j=1;j<=n-i+1;j++){
            if(v[b[j]]==0){
                c[k++]=b[j];
                v[b[j]]=j;
            }
            else{
                for(long long h=v[b[j]];h<=j;h++){
                    c[h]=0;
                    v[c[h]]=0;
                }
                c[k++]=b[j];
            }
        }
        for(long long j=1;j<=n-i+1;j++){
            if(c[j]!=0){
                ans[c[j]]++;
            }
        }
        for(long long j=1;j<=n-i+1;j++){
            b[j]=0;
            v[j]=0;
        }
    }
    for(long long i=1;i<=m;i++) cout<< ans[i] << ' ';
    return 0;
}
