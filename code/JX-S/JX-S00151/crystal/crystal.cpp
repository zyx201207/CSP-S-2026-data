#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,b=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=2;i++){
        while(a[i]!=a[i+2]){
            a[i]+=1;
            m--;
        }
        b++;
    }
    cout<<b+1;
    return 0;
}
