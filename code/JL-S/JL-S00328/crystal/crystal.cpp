#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans;
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            ans=0;
        }
        else{
            ans++;
        }
    }
    if(ans==0){
        cout<<n;
    }
    ans=0;
    for(int i=1;i<n;i++){
        if(a[i]+1==a[i+1]){
            ans++;
        }
        else{
            ans=0;
        }
    }
    if(ans!=0){
        if(m>=n*(n-1)/2){
            cout<<n;
        }
        else{
            for(int i=1;i<=n;i++){
                if(m<=i*(i-1)/2){
                    ans=i-1;
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
