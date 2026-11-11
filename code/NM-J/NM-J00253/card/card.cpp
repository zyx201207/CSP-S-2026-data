#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010],am[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = n;j>=1;j++){
            if(a[j]==i)am[i]=a[j];
        }
    }
    for(int i = 1 ; i <= m ;i++){
    cout<<am[i]<<' ';
    }
    return 0;
}
