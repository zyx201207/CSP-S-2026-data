#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[5000];
int main(){
    freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){

        cout<<a[i-1]++<<" ";
    }
    return 0;
}
