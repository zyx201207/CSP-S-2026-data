#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int maxn = 2*1e6+5;
int x[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i = 1;i<=t;i++){
        int cnt = 0;
        cin>>n>>d;
        for(int j = 1;j<=n;j++){
            cin>>x[j];
        }
        for(int j = 1;j<=n-3;j++){
            if(x[j+2]-x[j]<=d&&x[j+3]-x[j]>d)cnt++;;
        }
        cout<<cnt<<endl;
    }
}
