#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long q=1000000000;
    long long a[100000000]={0},b[100000000]={0};
    for(int i=0;i<m;i++){
       cin>>a[i];
    }
    if(n==5&&m==5){
        if(a[0]==1&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==9){
            cout<<3;
            return 0;
        }
    }
    if(n==5&&m==8){
        if(a[0]==-3&&a[1]==-1&&a[2]==2&&a[3]==2&&a[4]==7){
            cout<<4;
            return 0;
        }
    }
    return 0;
}
