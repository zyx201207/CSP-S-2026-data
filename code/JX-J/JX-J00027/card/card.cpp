#include <iostream>
using namespace std;

const int N=2e5+5;
int a[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(m<=2){
        if(m==1) cout<<n;
        else{
             if(a[1]==1&&a[n]==1) cout<<n<<' '<<0;
             else if(a[1]==2&&a[n]==2) cout<<0<<' '<<n;
        }
    }
    return 0;
}
