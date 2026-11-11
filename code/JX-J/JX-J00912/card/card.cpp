#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int w[500005];
int x[500005];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=a[i];
        w[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        int s=0;
        for(int i=1;i<=n;i++) {
            if(w[i]>1){
                s=i;
            }
        }
        for(int i=1;i<=n;i++) {
            if(i<s){
                w[i]=0;
            }
        }
        for(int i=1;i<=n;i++) {
            if(w[i]>0){
            x[a[i]]++;
        }
    }
}


    for(int i=1;i<=n;i++) {
        cout<<x[i]<<" ";
    }
    return 0;
}
