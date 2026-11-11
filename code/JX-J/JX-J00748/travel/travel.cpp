#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return ((a.size() == b.size()) && (a == b));
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    // 1. 判断两张车票对应的座位是否在同一节车厢;
    if(cmp(c1,c2)){
        cout << "1";
        // // 2. 判断张车票对应的座位是否在同一节车厢的同一排
        string p1 = "" + s1[0] + s1[1];
        //p1 += s1[1];
        string p2 = "" + s2[0] + s2[1];
        //p2 += s2[1];
        if(cmp(p1,p2)){
            cout << "1";
            // 3. 判断两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
            bool c1 = bool(int(s1[2] - 'A') <= 2), c2 = bool(int(s2[2] - 'A') <= 2);
            if(c1 == c2){
                cout << "1";
                // 4. 判断两张车票对应的座位是否相邻
                if(abs(int(s1[2] - 'A') - int(s2[2] - 'A')) == 1){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
