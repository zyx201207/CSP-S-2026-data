#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int N=2e5+8;
int a[N]={};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1) cout<<n;
    else{
        cout<<n-1<<" "<<n-1;
    }
    return 0;
}
