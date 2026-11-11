#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
char A[2]={'D','F'};
bool pd(char x,char y){
    int a = 0;
    int b = 0;
    for(int i = 0;i <= 1;i++){
        if(x == A[i])
            a = 1;
        if(y == A[i])
            b = 1;
    }
    if(a==b)
        return 1;
    else
        return 0;
}
bool pd2(char x,char y){
    char xx = x+1;
    char xxx = x-1;
    if(xxx == 'C')
        xxx = x;
    if(xx == 'D')
        xx = x;
    if(xx==y || xxx==y)
        return 1;
    else
        return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1[0]==b1[0] && a1[1]==b1[1]){
        cout << "1";
        if(a2[0]==b2[0] && b2[1]==a2[1]){
            cout << "1";
            if(pd(a2[2],b2[2])==1){
                cout << "1";
                if(pd2(a2[2],b2[2])==1)
                    cout << "1";
                else
                    cout << "0";
            }else
                cout << "00";
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
