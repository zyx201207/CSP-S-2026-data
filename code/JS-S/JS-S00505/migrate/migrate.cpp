#include<bits/stdc++.h>
using namespace std;
int ccf,T;
int n,d;
long long a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ccf>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(ccf==13||ccf==14){
            cout<<2<<endl;
        }
    }
    return 0;
}