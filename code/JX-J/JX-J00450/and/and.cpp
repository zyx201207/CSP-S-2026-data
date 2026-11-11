#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5]={};
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    int mi=-9999999;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                mi=max(mi,(a[i]&a[j]));
            }
        }
      cout<<mi;

    }else if(m==3){
         for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                mi=max(mi,(a[i]&a[j]&a[k]));
                }

            }
        }
    cout<<mi;
    }else if(m==3){
         for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                        for(int qwe=1;qwe<k;qwe++){
                            mi=max(mi,(a[i]&a[j]&a[k]&a[qwe]));
                        }

                }

            }
        }
    cout<<mi;
    }
    return 0;
}
