#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int x,y;
char s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> x >>  s1 >> c2 >> y >> s2;
    if(c1 == c2){
        cout << "1";
        if(x == y){
            cout << "1";
            if(s1 >= 'A'&&s1 <= 'C'&&s2 >= 'A'&&s2 <= 'C'||s1 >= 'D'&&s1 <= 'F'&&s2 >= 'D'&&s2 <= 'F'){
                cout << "1";
                char ch = min(s1,s2),ch1 = max(s1,s2);
                s1 = ch,s2 = ch1;
                if(s1 == 'A'&&s2 == 'B'||s1 == 'B'&&s2 == 'C'||s1 == 'D'&&s2 == 'F'){
                    cout << "1";   
                }else cout << "0";
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    cout << "\n";
    return 0;
}