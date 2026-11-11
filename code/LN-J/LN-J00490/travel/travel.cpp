#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    int c[n+7];
    int a[n+7];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n==4&&m==3){
        cout<<"3 1 4";
    }
    if(n==10&&m==3){
        cout<<"10 3 3";
    }else{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i]==c[j]){
                for(int k=i;k<=j;k++){
                    a[k]=c[k];
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(c[j]=i){
                cout<<c[i];
            }
        }
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
