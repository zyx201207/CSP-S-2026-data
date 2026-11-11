#include<bits/stdc++.h>

using namespace std;
long long n,m;
long long arr[200000000];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }long long num=arr[2]-arr[1];
    long long  ans=0;
    while(m>=0){
        ans++;
        m-=ans*num;

    }
    cout<<ans;
    return 0;
}
