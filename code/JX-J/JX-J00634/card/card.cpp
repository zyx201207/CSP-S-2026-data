#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=1e6;
long long a[N],b[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];

    }
    for(long long i=1;i<=n;i++){
        long long bsize=0;//b.lengh
        for(long long j=i;j<=n;j++){
            bool f=true;
            for(long long k=0;k<=bsize;k++){
                if(b[k]==a[j]) f=false;
            }
            if(f==true){
                bsize++;
                b[bsize]=a[j];
            }
            else{
                for(bool s=false;s==false;){
                    if(a[j]==b[bsize]) s=true;
                    bsize--;
                }
                bsize++;
                b[bsize]=a[j];
            }
        }
        for(long long j=1;j<=bsize;j++){
            ans[b[j]]++;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
