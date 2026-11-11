#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ma=0;
    int a[200005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>ma){
                ma=a[i];
            }
        }
        cout<<ma;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>ma){
                    ma=(a[i]&a[j]);
                }
            }
        }
        cout<<ma;
    }
    else if(m==n){
        ma=a[1];
        for(int i=2;i<=n;i++){
            ma=(ma&a[i]);
        }
        cout<<ma;
    }
    return 0;
}
