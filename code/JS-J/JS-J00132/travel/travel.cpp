#include <bits/stdc++.h>
#define int long long
using namespace std;

bool same_part(char ch1,char ch2){
    if (ch1=='A'){
        if (ch2=='B' || ch2=='C'){
            return true;
        }else{
            return false;
        }
    }else if (ch1=='B'){
        if (ch2=='A' || ch2=='C'){
            return true;
        }else{
            return false;
        }
    }else if (ch1=='C'){
        if (ch2=='A' || ch2=='B'){
            return true;
        }else{
            return false;
        }
    }else if (ch1=='D'){
        if (ch2=='F'){
            return true;
        }else{
            return false;
        }
    }else{
        if (ch2=='D'){
            return true;
        }else{
            return false;
        }
    }
}

bool is_near(char ch1,char ch2){
    if (abs(ch1-ch2)==1){
        return true;
    }else{
        return false;
    }
}

signed main(){
    freopen("travel.in","r",stdin);      //Remember change me!!
    freopen("travel.out","w",stdout);    //Remember change me!!

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const char endl='\n';

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    if (s1[0]==s2[0] && s1[1]==s2[1]){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    if ((s1[0]==s2[0] && s1[1]==s2[1]) && same_part(s1[2],s2[2])){
        cout << "1";
    }else{
        cout << "00";
        return 0;
    }
    if (is_near(s1[2],s2[2])){
        cout << "1";
    }else{
        cout << "0";
        return 0;
    }
    cout << endl;

    return 0;
}
