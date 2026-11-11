#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[500005],mid,ans=0,cnt=0;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    mid=n/2+1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[mid])
            ans++;
    }
    for(int i=1;i<=mid;i++){
        a[i]=a[i]+(a[mid]-a[i]);
        cnt=cnt+a[mid]-a[i];
        if(cnt>=m){
            cout<<ans;
        }else{
            ans++;
        }
    }
    cout<<ans-1;


    return 0;
}
