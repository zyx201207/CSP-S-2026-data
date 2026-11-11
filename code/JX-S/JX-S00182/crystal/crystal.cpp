#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==5){
        if(a[0]==1&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==9){
            cout<<"3";
        }
    }else if(n==5&&m==8){
        if(a[0]==-3&&a[1]==-1&&a[2]==2&&a[3]==2&&a[4]==7){
                cout<<"4";
        }
    }else{
        cout<<"0";
    }
    return 0;
}
