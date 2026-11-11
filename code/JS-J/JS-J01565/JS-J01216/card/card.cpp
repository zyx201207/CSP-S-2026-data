#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,d,k=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d;
        if(k<=m){
            cout<<d<<' ';
            k++;
        }
    }
    return 0;
}
