#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int o=n;
    for(int k=1;k<=m;k++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            int flag=0;
            for(int j=i+1;j<=n;j++){
                if(a[i]==b[j]){
                    flag=1;
                }
            }
            if(flag==1){
                for(int qw=1;qw<=o;qw++){
                    if(b[qw]==a[i]){
                        b[qw]=-1;
                    }
                }
                for(int k=i;k<=n;k++){
                    b[k]=-1;
                }
                b[++o]=a[i];
            }
            else{
                b[++o]=a[i];
            }
            int cy=0;
            for(int l=1;l<=o;l++){
                if(b[l]==a[i]){
                    cy=1;
                }
            }
            if(cy==1){
                cnt++;
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
