#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
long long pre[500100];
ifstream fin("crystal.in");
ofstream fout("crystal.out");
bool test(int p,int q){
    return pre[q]-pre[p-1]+m>=a[q]*(q-p+1);
}
int main(){
    fin>>n>>m;
    for(long long i=1;i<=n;i++){
        fin>>a[i];
    }
    sort(a,a+n);
    pre[0]=0;
    for(long long i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    long long ans=0;
    for(long long i=1;i<n;i++){
        long long l=1;
        long long r=i;
        while(l<r){
            long long mid=(l+r)/2;
            if(test(mid,i)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    fout<<ans;
}
