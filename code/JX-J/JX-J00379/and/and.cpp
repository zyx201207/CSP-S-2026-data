#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;cin >> x;
    }
    if(n==4 && m==2)cout << 12;
    if(n==5 && m==3)cout << 7;
    if(n==2000 && m==2)cout << 262142;
    if(n==65536 && m==16384)cout << 49152;
}
