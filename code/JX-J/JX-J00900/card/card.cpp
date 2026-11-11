#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n<<' '<<n<<' '<<m;


    return 0;
}
