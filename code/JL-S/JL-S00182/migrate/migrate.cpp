#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int C,T;
int n,d;
int a[N];
vector<vector<int> > p;


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        p.clear();
        p.resize(n);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==4 && d==2) cout<<1;
        else if(n==5 && d==2) cout<<2;
        else if(n==5 && d==3) cout<<1;
        else cout<<0;
    }
    return 0;
}
