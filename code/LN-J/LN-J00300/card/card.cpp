#include<bits/stdc++.h>;
using namespace std;
int n,m;
int a[1000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[1]<<a[2]<<a[0];
    return 0;
}

