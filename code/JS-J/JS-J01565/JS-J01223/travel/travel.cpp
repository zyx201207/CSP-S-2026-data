#include <bits/stdc++.h>
using namespace std;

string c1 , s1 , c2 , s2;

int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
            bool t1 , t2;
            if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
                t1 = 0;
            }else{
                t1 = 1;
            }
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                t2 = 0;
            }else{
                t2 = 1;
            }
//            cout << endl << t1 << " " << t2 << endl;
            if(t1 == t2){
                cout << 1;
                if(abs((s1[2] - 'A') - (s2[2] - 'A')) == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << 0;
                cout << 0;
            }
        }else{
            cout << 0;
            cout << 0;
            cout << 0;
        }
    }else{
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
