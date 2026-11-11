#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
long long arr[M],brr[M];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,nans=0,nshu=0,ans=-1;
    arr[0]=0;
    brr[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    for(int i=1;i<=n;++i){
        brr[i]=arr[i]-arr[i-1];
        nshu+=nans*brr[i];
        if(nshu<=m){
            ++nans;
            ans=max(nans,ans);
        }
        else{
            for(int j=i-nans;j<=i;++j){
                nshu-=brr[j];
                if(nshu<=m){
                    nans=i-j;
                    break;
                }
            }
        }
    }
    printf("%lld",ans);
}
