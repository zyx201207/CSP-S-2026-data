#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100001]={0};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long max=-1;
    long long s[100001]={0};
    for(long long i=1;i<n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(long long i=1;i<=n;i++){
        long long k=0,j=i,sum=0;
        for(long long j=i;j>=0;j--){
            k=k+s[j];
            if(k<=m){
                sum++;
            }
            else break;

        }
        if(max<sum) max=sum;
    }
    cout<<max;
    return 0;
}
