#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int num1=c1[0]-'0',num2=c2[0]-'0';
    num1=num1*10+c1[1]-'0';
    num2=num2*10+c2[1]-'0';
    if(num1!=num2){
        cout << "0000";
        return 0;
    }
    else{
        cout << 1;
        int l1=s1[0]-'0',l2=s2[0]-'0';
        l1=l1*10+s1[1]-'0';
        l2=l2*10+s2[1]-'0';
        if(l1!=l2){
            cout << "000";
            return 0;
        }
        else{
            cout << 1;
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
                cout << 1;
                if(s1[2]+2==s2[2]||s1[2]-2==s2[2]){
                    cout << 0;
                    return 0;
                }
                else{
                    cout << 1;
                    return 0;
                }
            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
                cout << 11;
                return 0;
            }
            else{
                cout << "00";
                return 0;
            }
        }
    }
    return 0;
}
