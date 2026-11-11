#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long k;
    long long sum=1;
    if(n%2==0){
        k=a[n/2+1];
        for(int i=n/2;i>=1;i--){
            while(m!=0){
                m-=k-a[i];
                sum++;
            }
        }
    }
    else{
        k=(a[n/2]+a[n/2+1])/2;
        for(int i=n/2;i>=1;i--){
            while(m!=0){
                m-=k-a[i];
                sum++;
            }
        }
    }
    cout<<sum/2;
    return 0;
}

