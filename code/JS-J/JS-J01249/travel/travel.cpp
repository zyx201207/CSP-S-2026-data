#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a,b;
    a = s1[2];
    b = s2[2];
    int seat1 = 0,seat2 = 0;
    for(int i = 0;i < s1.length() - 1;i++){
        seat1 = seat1 * 10 + s1[i] - '0';
        seat2 = seat2 * 10 + s2[i] - '0';
    }
    bool q1,q2,q3,q4;
    q1 = (c1 == c2);
    if(!q1){
        cout << "0000\n";
        return 0;
    }
    q2 = (seat1 == seat2);
    if(!q2){
        cout << "1000\n";
        return 0;
    }
    bool flg1 = (a <= 'C' && b <= 'C');
    bool flg2 = (a >= 'D' && b >= 'D');
    if(flg1 || flg2){
        q3 = 1;
        if(flg1){
            q4 = (abs(a - b) == 1);
        }else if(flg2){
            cout << "1111\n";
        }
        return 0;

    }else{
        cout << "1100\n";
        return 0;
    }
}
