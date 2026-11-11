#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2, b = "";
    int d = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        for (int i = 0;i < 2;i++){
            if (s1[i] == s2[i]) d++;
        }
        if (d == 2){

            if(s1[2] >= 'D' && s2[2] >= 'D' || s1[2] <= 'C' && s2[2] <= 'C'){
                if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
                    cout << "1111";
                }else cout << "1110";
            }else cout << "1100";
        }else cout << "1000";
    }else cout << "0000";



    return 0;
}
