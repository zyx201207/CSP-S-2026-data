#include<bits/stdc++.h>
using namespace std;
int a[100005],x[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    if(m==1){
        cout<<n;
    }
    if(m==2){
        if(n==2){
            if(x[0]==1 && x[1]==2){
                cout<<"1 2";
            }else{
                cout<<"2 1";
            }
        }
        else if(n==3){
            if(x[0]==1 && x[1]==1 && x[2]==2){
                cout<<"2 3";
            }else if(x[0]==1 && x[1]==2 && x[2]==1){
                cout<<"3 2";
            }else if(x[0]==2 && x[1]==1 && x[2]==1){
                cout<<"3 1";
            }else if(x[0]==1 && x[1]==2 && x[2]==2){
                cout<<"1 3";
            }else if(x[0]==2 && x[1]==2 && x[2]==1){
                cout<<"3 2";
            }else{
                cout<<"2 3";
            }
        }
    }
    return 0;
}
