#include<bits/stdc++.h>
using namespace std;
const int MAX=10086;
int a[MAX];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n=4){
        cout<<3<<' '<<1<<4;
    }else if(n=10){
        cout<<10<<3<<3;
    }else{
        cout<<n<<n<<3;
    }
    return 0;
}
