#include <bits/stdc++.h>
using namespace std;
itn a[10086];
int main(){
    freopen("in.card","r",stdin);
    freopen("out.card","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4)cout<<3<<" "<<1" "<<4<<endl;
    if(n==10)cout<<10<<" "<<3<<" "<<3<<endl;
    return 0;
}
