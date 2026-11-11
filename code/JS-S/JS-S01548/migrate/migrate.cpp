#include<bits/stdc++.h>
using namespace std;

int c,T;
int n,lgn,n1;
long long d,x[2000005];
int ca[2000005];
long long ans;
queue<int> st;
queue<int> en;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
        cout<<(n-1)*(x[1]-x[0])/d<<endl;
    }
    return 0;
}
