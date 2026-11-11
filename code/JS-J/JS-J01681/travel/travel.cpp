#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cr,cx,sr = 0,sx = 0;
    char srr,sxx;
    cin >> cr;
    for(int i = 0;i < 2;i++){
        cin >> srr;
        sr = sr * 10 + (int)(srr - '0');
    }
    cin >> srr;
    cin >> cx;
    for(int i = 0;i < 2;i++){
        cin >> sxx;
        sx = sx * 10 + (int)(sxx - '0');
    }
    cin >> sxx;
    if(cr != cx){
        cout << "0000\n";
        return 0;
    }
    if(sr != sx){
        cout << "1000\n";
        return 0;
    }
    sr = (int)(srr - 'A');
    sx = (int)(sxx - 'A');
    bool lr = 0,lx = 0;
    if(sr <= 2) lr = 1;
    if(sx <= 2) lx = 1;
    if(lr != lx){
        cout << "1100\n";
        return 0;
    }
    if(abs(sr - sx) != 1){
        cout << "1110\n";
        return 0;
    }
    cout << "1111\n";
    return 0;
}