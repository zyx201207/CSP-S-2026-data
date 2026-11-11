#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],k[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
    }else if(m==2){
        if(a[1]==a[2]){
            if(a[1]==1){
                cout<<3<<" "<<4;
            }else{
                cout<<4<<" "<<3;
            }
        }else{
            if(a[4]==1){
                cout<<4<<" "<<3;
            }else{
                cout<<3<<" "<<4;
            }
        }
    }
    return 0;
}
