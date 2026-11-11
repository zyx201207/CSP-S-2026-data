#include <bits/stdc++.h>
using namespace std;


int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << (c1 == c2);
        string ss1,ss2,ss3,ss4;
        for(int i = 0 ; i < s1.length() ; i++){
            if(s1[i] >= 'A' && s1[i] <= 'F'){
                ss2 += s1[i];
            }else{
                ss1 += s1[i];
            }
        }
        for(int i = 0 ; i < s2.length() ; i++){
            if(s2[i] >= 'A' && s2[i] <= 'F'){
                ss4 += s2[i];
            }else{
                ss3 += s2[i];
            }
        }
        if(ss1 == ss3){
            cout << (ss1 == ss3);
            if((ss2 >= "A" && ss2 <= "C" && ss4 >= "A" && ss4 <= "C") || (ss2 >= "D" && ss2 <= "F" && ss4 >= "D" && ss4 <= "F") || (ss4 >= "A" && ss4 <= "C" && ss2 >= "A" && ss2 <= "C") || (ss4 >= "D" && ss4 <= "F" && ss2 >= "D" && ss2 <= "F")){
                cout << 1;
                if((ss2 == "A" && ss4 == "B") || (ss2 == "B" && ss4 == "C") ||(ss2 == "D" && ss4 == "F") || (ss2 == "B" && ss4 == "A") || (ss2 == "C" && ss4 == "B") ||(ss2 == "F" && ss4 == "D")){
                        cout << 1;
                }else if((ss2 == "C" && ss4 == "D") || (ss2 == "D" && ss4 == "C")){
                    cout << 0;
                }
            }else{
                cout << 0;
                if((ss2 == "A" && ss4 == "B") || (ss2 == "B" && ss4 == "C") ||(ss2 == "D" && ss4 == "F") || (ss2 == "B" && ss4 == "A") || (ss2 == "C" && ss4 == "B") ||(ss2 == "F" && ss4 == "D")){
                    cout << 1;
                }else if((ss2 == "C" && ss4 == "D") || (ss2 == "D" && ss4 == "C")){
                    cout << 0;
                }

            }
        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0 << 0;
    }

    return 0;
}
