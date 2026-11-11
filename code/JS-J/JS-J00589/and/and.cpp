#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(m==1){
        int maxn=0;
        for(int i=1;i<=n;i++){
            if(arr[i]>maxn){
                maxn=arr[i];
            }
        }
        cout<<maxn<<endl;
    }else if(m==n){
        long long s=arr[1] & arr[2];
        for(int i=3;i<=n;i++){
            s=s & arr[i];
        }
        cout<<s<<endl;
    }else if(m==2){
        long long ans=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if((arr[i] & arr[j]) > ans){
                    ans=(arr[i] & arr[j]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
