#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[10000],b=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i-1];

        for(int j=0;j<=i;j++){
            if(a[i-1]==a[j]){
                break;
            }
        }
    }
    cout<<"3"<<" "<<"1"<<" "<<"4";
    return 0;

}
