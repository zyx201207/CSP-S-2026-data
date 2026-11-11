#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    cout<<n;
    for(int i=1;i<m;i++){
        cout<<(i+m)/2+i;
    }
    return 0;
}
