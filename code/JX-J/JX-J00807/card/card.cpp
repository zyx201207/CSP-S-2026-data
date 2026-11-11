#include<bits/stdc++.h>
using namespace std;

long long ar[500005]={0};
long long arr[500005]={0};
long long arrr[500005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>ar[i];
    }
    for(long long i=1;i<=n;++i){
        for(long long j=1;j<500000;++j){
            arr[i]=0;
        }
        long long num=0;
        long long cnt=0;
        for(long long j=i;j<=n;++j){
            long long l=j-i+1;
            arr[l]=ar[j];
            for(long long k=1;k<j;++k){
                if(arr[l]==arr[k]){
                    for(long long h=k+1;h<=l;++h){
                        arr[h]=0;
                        l=l-k+1;
                        num=l;
                    }
                }
            }
            for(long long j=1;j<=num;++j){
                arrr[i]+=1;
            }
        }
    }
    for(long long i=1;i<=m;++i){
        cout<<arrr[i]<<" ";
    }

    return 0;
}
