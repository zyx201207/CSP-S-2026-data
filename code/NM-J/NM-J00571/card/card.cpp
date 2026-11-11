#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[100010];
int main(){
    int ans=0;
    int b=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=a[1];
        if(a[i]>ans){
            ans=a[i];
            a[i]=0;
        }
        else a[i]=0;
    }b=ans;
    while(m--){
        for(int i=1;i<=n;i++){
            if(a[i]>ans){
            ans=a[i];
            a[i]=0;
        }
}       b&=ans;
    }
    cout<<b;
    return 0;
}
