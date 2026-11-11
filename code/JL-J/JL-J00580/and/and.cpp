#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=0;
        for(int j=a[i];j>=0;j=j/2){
            if(j==0){
                break;
            }
            b[i]+=j%2+(j/2%2)*10;
        }
    }
    if(m==1){
        int ans=a[1];
        for(int i=2;i<n;i++){
            if(a[i]>ans){
                ans=a[i];
            }
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=b[1] and b[2];
        for(int i=1;i<=n;i++){
            for(int j=3;j<=n;j++){
                 if((b[i] and b[j])>ans){
                    ans=b[i] and b[j];
                 }
            }
        }
        cout<<ans;
    }
    return 0;
}
