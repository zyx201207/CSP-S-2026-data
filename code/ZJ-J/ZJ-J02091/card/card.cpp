#include <bits/stdc++.h>
using namespace std;
int a[500086],cnt[500086],td[500086];;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        int g=i;
        for(int j=i;j<=n;j++){
            td[a[j]]++;
            if(td[a[j]]>1){
                for(int k=g;k<j;k++){
                    td[a[k]]--;
                }
                g=j;
            }
        }
        for(int j=g;j<=n;j++){
            cnt[a[j]]++;
        }
        for(int j=1;j<=n;j++){
            td[j]=0;
        }
    }
    
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }    
    return 0;
}