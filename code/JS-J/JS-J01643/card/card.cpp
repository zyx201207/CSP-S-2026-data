#include<iostream>
using namespace std;
int n,m;
bool f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        if(a[i]>a[i+1]){
            f=0;
        }
    }
    if(f==1){
        cout<<m;
        for(int i=1;i<=m-1;i++){
            cout<<" "<<m;
        }
        return 0;
    }
    return 0;
}
