#include<bits/stdc++.h>
using namespace std;
int n, m, a[500003], lst[500003];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        lst[a[i]] = i;
    }
    for(int i = 1;i <= m;i++)cout<<lst[a[i]]<<' ';
}
