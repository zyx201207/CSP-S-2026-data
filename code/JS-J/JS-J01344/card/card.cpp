#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
long long n,m;
int a[N] ;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=cnt;j<=n;j++){
            cin>>a[i];
        }
    }
    return 0;
}
