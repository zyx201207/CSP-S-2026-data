#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    long long x=0;
    long long a=111111111;
    if(m==1){
        for(int i=0;i<n;i++){
            x=max(x,num[i]&a);
        }
        cout<<x;
    }
    else if(m==n){
        for(int i=0;i<n-1;i++){
                x=x+num[i]&num[i+1];
        }
        cout<<x;
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                x=max(x,num[i]&num[j]);
            }
        }
        cout<<x;
    }
    return 0;
}
