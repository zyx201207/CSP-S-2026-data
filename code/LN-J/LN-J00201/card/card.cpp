#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool f=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]){
            f=true;
        }
    }
    if(f==true){
        while(m--){
            cout<<1<<" ";
        }
    }else{
        while(m--){
            cout<<n<<" ";
        }
    }
    return 0;
}
