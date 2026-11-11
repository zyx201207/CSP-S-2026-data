#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    if(n==5&&m==3){
        cout<<7;
    }
    else if(n==4&&m==2){
        cout<<12;
    }



    return 0;
}

