#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0;
    for(long long i=1;i<=n;i++){
        long long k=0;
        long long cha=0;
        for(long long j=i;j>=1;j--){
            long long kk=a[i]-a[j];
            if((k+kk)<=m){
                k+=kk;
                cha++;
            }
            else{
                break;
            }
        }
        sum=max(sum,cha);
    }
    cout<<sum;
    return 0;
}
