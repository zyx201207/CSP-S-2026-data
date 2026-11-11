#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[1010]={};
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<"1";
    }else{
        if(m==1){
            cout<<n;
        }
    }




    return 0;
}
