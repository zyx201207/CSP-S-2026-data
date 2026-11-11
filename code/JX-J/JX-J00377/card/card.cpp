#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int tong[300005]={};
    int a[500005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p=0;
    for(int i=1;i<=n;i++){
        if(tong[a[i]]!=0){
            for(int j=i-1;j>=n;j--){
            tong[a[j]]--;
                if(a[j]==a[i]){
                    break;
                }
            }
        }
        tong[a[i]++];
        for(int z=1;z<=n;z++){
            if(tong[a[z]]>0 and a[z]==i){
                p+=tong[a[z]];
            }
        }
    }
    cout<<p<<" ";
    int b[500005]={};
    int x=500005;
    for(int i=n-1;i>=1;i--){
        if(tong[a[i]]!=0){
            b[x]=a[i];
            tong[a[i]]--;
            x--;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=0){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
