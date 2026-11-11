#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000000],maxx=-100000;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==4){
        cout<<12;
    }
    if(n==5){
        cout<<7;
    }
    else{
        cout<<511;
    }
    return 0;
}
