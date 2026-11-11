#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int c,t,n,d;
int a[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>t;

    while(t--){
        cin>>n>>d;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        c=a[2]-a[1];
        cout<<c*(n-1)/d<<endl;
    }
    return 0;
}
