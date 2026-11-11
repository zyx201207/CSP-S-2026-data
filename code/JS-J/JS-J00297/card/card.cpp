#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int ans[500010]={};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    while(i<=n){
        int b[500010]={0};
        int c=0;
        for(int j=i;j<=n;j++){
            for(int k=i;k<j-c;k++){
                if(b[k]==a[j]){
                    c=j-k;
                }
            }
            b[j-c]=a[j];
        }
        for(int j=i;j<=n-c;j++){
            ans[b[j]]++;
        }
        i++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
