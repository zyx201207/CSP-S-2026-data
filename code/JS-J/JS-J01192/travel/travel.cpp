#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    else{
        int a, b;
        a = (s1[0]-'0')*10 + s1[1] - '0';
        b = (s2[0]-'0')*10 + s2[1] - '0';
        if(a!=b){
            cout << "1000";
            return 0;
        }
        else{
            if(s1[2]>='D'&& s2[2]>='D'){
                cout << "1111";
                return 0;
            }
            if(s1[2]<'D'&&s2[2]<'D'){
                if(s1[2]-s2[2] == 1 || s2[2] - s1[2] == 1){
                    cout << "1111";
                }
                else{
                    cout << "1110";
                }
            }
            else{
                cout <<"1100";
            }
        }
    }
    return 0;
}
