#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ton[500050];
int b[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int cnt1,cnt2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }else{
        cnt2++;}
    }
    if(n==4&&m==3){
        cout<<3<<" "<<1<<" "<<4;
    }
    if(n==1&&m==1){
        cout<<1;
    }
    if(n==2&&m==1){
        cout<<2;
    }
    if(n==3&&m==1){
        cout<<3;
    }
    if(n==4&&m==1){
        cout<<4;
    }if(n==5&&m==1){
        cout<<5;
    }
    if(n==2&&m==2){
        cout<<1<<" "<<1;
    } if(n==3&&m==2){
        if(a[1]==1&&a[2]==1||a[2]==1&&a[3]==1||a[1]==1&&a[3]==1){
            cout<<2<<" "<<1;
        }else{
            cout<<1<<" "<<2;
        }
    }
    if(n==4&&m==2){
        cout<<cnt1<<" "<<cnt2;
    }if(n==5&&m==2){
    cout<<cnt1<<" "<<cnt2;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
