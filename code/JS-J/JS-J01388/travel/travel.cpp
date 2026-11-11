#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout)
    char n[13];
    cin >> n;
    if (n[0]==n[7] && n[1]==n[8]){
        if (n[3]==n[10] && n[4]==n[11]){
            if ((n[5]=="D" && n[12]=="F") || (n[5]=="F" && n[12]=="D")){
                cout << "1111";
            }
            else{
                if ((n[5]=="A" && (n[12]=="B" || n[12]=="C")) || (n[5]=="B" && (n[12]=="A" || n[12]=="C")) || (n[5]=="C" && (n[12]=="A" || n[12]=="B"))){
                    if (n[5]=="B" || n[12]=="B"){
                        cout << "1111";
                    }
                    else{
                        cout << "1110";
                    }
                }
                else{
                    cout << "1100";
                }
            }
        }
        else{
            cout << "1000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
