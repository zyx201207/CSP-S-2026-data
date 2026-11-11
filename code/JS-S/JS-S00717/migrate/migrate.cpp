#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+5;
int x[MAXN];
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            int xx=(d+x[2]-x[1])/(x[2]-x[1])+1;
            cout<<n-xx+1;
        }
    }



}
