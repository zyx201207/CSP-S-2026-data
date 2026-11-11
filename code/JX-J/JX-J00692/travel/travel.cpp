#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool samecx = 0;
    int cx1 = c1[1] - '0';
    if(c1[0] != '0'){
        int k = c1[0] - '0';
        cx1 += k * 10; 
    }
    int cx2 = c2[1] - '0';
    if(c2[0] != '0'){
        int k = c2[0] - '0';
        cx2 += k * 10;
    }
    int p1 = s1[1] - '0';//Adepai
    if(s1[0] != '0'){
        int k = s1[0] - '0';
        p1 += k * 10;
    }
    int p2 = s2[1] - '0';//Bde pai
    if(s2[0] != '0'){
        int k = s2[0] - '0';
        p2 += k * 10;
    }
    char seat1 = s1[2];
    char seat2 = s2[2];
    if(cx1 == cx2){
        cout << 1;
        if(p1 == p2){
            cout << 1;
            if(((seat1 == 'A' || seat1 == 'B' || seat1 == 'C') && (seat2 == 'A' || seat2 == 'B' || seat2 == 'C')) || ((seat1 == 'D' || seat1 == 'F') && (seat2 == 'D' || seat2 == 'F'))){
                cout << 1;
                if((seat1 == 'A' && seat2 == 'B') || (seat1 == 'B' && seat2 == 'C') || (seat1 == 'B' && seat2 == 'A') || (seat1 == 'C' && seat2 == 'B') || (seat1 == 'D' && seat2 == 'F') || (seat1 == 'F' && seat2 == 'D')){
                    cout << 1 << '\n';
                }
                else{
                    cout << 0 << '\n';
                }
            }
            else{
                cout << "00" << '\n';
            }
            
        }
        else{
            cout << "000" << '\n';
        }
        
    }
    else{
        cout << "0000";
    }

    return 0;
}
//diff -w a b//a,bshiwenjian