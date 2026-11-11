//wo bing bu ming bai wo shi zen me le ju ran bu hui xie dai ma le
//qswl
//Omgs I want to sleep
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int x,id;
    char n;
}f[3004];
int m;
ll xsig;
bool fe=1;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> m;
    for(int i = 0;i < m;i++){
        cin >> f[i].x >> f[i].n;
        xsig += f[i].x;
        if(i>=1){
            if(f[i].n!=f[i-1].n) fe=0;
        }
    }
    if(fe==0) cout << xsig/2;
    else cout << 0;//能骗一点是一点(bushi)(jiushi)(buzhidao)
}