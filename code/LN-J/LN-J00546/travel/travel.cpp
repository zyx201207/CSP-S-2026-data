#include <bits/stdc++.h>
using namespace std;

int res[4];

int return_num(char n){
    if (n=='A')return 1;
    if (n=='B')return 2;
    if (n=='C')return 3;
    if (n=='D')return 5;
    if (n=='F')return 6;
    return 0;
}
int left2[3]={1,2,3};
int right2[2]={5,6};

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string zw1,zw2;
    string cx1,cx2;
    cin >> cx1 >> zw1>>cx2>>zw2;

    if (cx1==cx2){
        res[0] = 1;
    }else{
        cout<<"0000";
        return 0;
    }

    if (zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
        res[1] = 1;
    }else {
        cout <<"1000";
        return 0;
    }

    int tai1 = return_num(zw1[2]);
    int tai2 = return_num(zw2[2]);

    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    for (int i=0;i<3;i++){
        if (tai1==left2[i])flag1 = true;
        if (tai2==left2[i])flag2 = true;
    }

    for (int i=0;i<2;i++){
        if (tai1==right2[i])flag3 = true;
        if (tai2==right2[i])flag4 = true;

    }if ((flag1&&flag2)||(flag3&&flag4)){
        res[2]=1;
    }else{
        cout<<"1100";
        return 0;
    }

    if ((tai1==tai2-1)||(tai2==tai2+1)){
        cout<<"1111";
    }else{
        cout<<"1110";
    }
    return 0;
}
