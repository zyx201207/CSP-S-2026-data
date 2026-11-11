#include<bits/stdc++.h>
using namespace std;
constexpr long long N=2*1E5+3;
long long n,m;
long long a[N];
int b[20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }else if(m==n){
        long long ans=a[n-1];
        for(int i=n-2;i>=0;i--){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else{
        long long mx=0;
        do{
            long long s=a[0];
            for(long long i=1;i<m;i++){
                s&=a[i];
            }
            mx=max(s,mx);
        }while(next_permutation(a,a+n));
        cout<<mx;
        return 0;
    }
    return 0;
}