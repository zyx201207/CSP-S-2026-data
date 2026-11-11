#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1]={},ans[m+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[n+1]={},size=0;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=size;k++){
                if(a[j]==b[k]){
                    for(int l=k;l<=size;l++){
                        b[l]=-1;
                    }
                    break;
                }
            }
            size++;
            b[size]=a[j];
        }
        for(int j=1;j<=size;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
