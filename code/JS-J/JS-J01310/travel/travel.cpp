#include<bits/stdc++.h>
using namespace std;

bool inthe(char small, string big){
    for(auto &a: big)
        if(small == a)
            return true;
    return false;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string one[2], two[2], ans = "";
    cin>>one[0]>>one[1]>>two[0]>>two[1];

    if(one[0] == two[0]){
        ans += '1';
        string num1 = "", num2 = "";
        num1 += one[1][0]; num1 += one[1][1];
        num2 += two[1][0]; num2 += two[1][1];
        if(num1 == num2){
            ans += '1';
            if(inthe(one[1][2], "ABC") && inthe(two[1][2], "ABC")){
                ans += '1';
                if(one[1][2] + 1 == two[1][2] || one[1][2] - 1 == two[1][2]){
                    ans += '1';
                }else ans += '0';
            }else if(inthe(one[1][2], "DF") && inthe(two[1][2], "DF")){
                ans += "11";
            }else ans += "00";
        }else ans += "000";
    }else{ans += "0000";}

    cout<<stoi(ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
