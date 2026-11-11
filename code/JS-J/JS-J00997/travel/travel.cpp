#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool train = false;
bool seat1 = false;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;
    for(int i = 0; i < 2; i++){
        if(c1[i] == c2[i]){
            train = true;
        }else{
            train = false;
            break;
        }
    }
    if(train == false){
        cout << "0" << "0" << "0" << "0";
        return 0;
    }else{
        cout << "1";
    }
    for(int i = 0; i < 2; i++){
        if(s1[i] == s2[i]){
            seat1 = true;
        }else{
            seat1 = false;
            break;
        }
    }
    if(seat1 == false){
        cout << "0" << "0" << "0";
        return 0;
    }else{
        cout << "1";
    }
    if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
        cout << "1";
        if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1){
            cout << "1";
        }else{
            cout << "0";
            return 0;
        }
    }else if(s1[2] == 'D' && s2[2] == 'F' || s2[2] == 'D' && s1[2] == 'F'){
        cout << "1" << "1";
        return 0;
    }else{
        cout << "0" << "0";
        return 0;
    }

    cout << endl;
    return 0;
}
