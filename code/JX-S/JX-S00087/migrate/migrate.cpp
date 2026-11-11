#include <iostream>
#include <cmath>
using namespace std;
const int N = 2e6+10;
int a[N];

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha = abs(a[2] - a[1]);
        if(cha>=d||d!=cha*2||d%2==1){
            cout<<0<<"\n";
            continue;
        }
        cout<<(n-3)<<"\n";
    }

    return 0;
}
