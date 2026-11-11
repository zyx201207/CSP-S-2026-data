#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,p=0,l=1;
    cin>>n>>m;
    int a[n]={},b[m+1]={};
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]<a[0]){
            l=0;
        }
    }
    if(l==1){
        int r=0;
        for(int i=1;i<=m;i++){
            for(int j=r;j<n;j++){
                if(a[j]!=i){
                    cout<<j;
                    r=j;
                    break;
                }
            }
        }
        cout<<n;
        return 0;
    }
    for(int i=0;i<n;i++){
        p=i;
        for(int j=i;j<n;j++){


            for(int k=j+1;k<n;k++){
                if(a[j]==a[k]){
                    p=k;
                    j=k;
                }
            }
        }
        for(int j=p;j<n;j++){
            b[a[j]]++;

        }


    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
