#include<bits/stdc++.h>
#define int long long
using namespace std;
int ca, cb;
string sa, sb;
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> ca >> sa;
    cin >> cb >> sb;
    if(ca != cb){
        cout << "0000" << '\n';
        return 0;
    }else{
        int x, y;
        char cx, cy;
        for(int i = 0; i < 3; i++){
            if(i < 2){
                x = x * 10 + sa[i] - '0';
            }else{
                cx = sa[i];
            }
        }
        for(int i = 0; i < 3; i++){
            if(i < 2){
                y = y * 10 + sb[i] - '0';
            }else{
                cy = sb[i];
            }
        }
        if(x != y){
            cout << 1000 << '\n';
            return 0;
        }else{
            if(cx == 'D'){
                if(cy != 'E'){
                    cout << 1100 << '\n';
                    return 0;
                }else{
                    cout << 1111 << '\n';
                    return 0;
                }
            }else if(cx == 'E'){
                if(cy != 'D'){
                    cout << 1100 << '\n';
                    return 0;
                }else{
                    cout << 1111 << '\n';
                    return 0;
                }
            }else if(cx == 'A'){
                if(cy == 'B'){
                    cout << 1111 << '\n';
                    return 0;
                }else if(cy == 'C'){
                    cout << 1110 << '\n';
                    return 0;
                }else{
                    cout << 1100 << '\n';
                    return 0;
                }
            }else if(cx == 'B'){
                if(cy == 'C' || cy == 'A'){
                    cout << 1111 << '\n';
                    return 0;
                }else{
                    cout << 1100 << '\n';
                    return 0;
                }
            }else if(cx == 'C'){
                if(cy == 'B'){
                    cout << 1111 << '\n';
                    return 0;
                }else if(cy == 'A'){
                    cout << 1110 << '\n';
                    return 0;
                }else{
                    cout << 1100 << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}